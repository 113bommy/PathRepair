#include <bits/stdc++.h>
using namespace std;
const int N = 5040;
char s1[N], s2[N];
int num[30], a[N][30];
multiset<int> st;
int gao(int now) {
  multiset<int>::reverse_iterator it;
  for (it = st.rbegin(); it != st.rend(); it++) {
    if ((*it) > s2[now] - 'a') {
      return 1;
    } else if ((*it) < s2[now] - 'a') {
      return -1;
    }
    now++;
  }
  return 0;
}
int main(void) {
  scanf("%s", s1);
  scanf("%s", s2);
  int len = strlen(s1);
  memset(num, 0, sizeof(num));
  memset(a, 0, sizeof(a));
  for (int i = 0; i < len; i++) {
    st.insert(s1[i] - 'a');
  }
  if (gao(0) <= 0) {
    printf("-1\n");
  } else {
    int flag = 0;
    for (int i = 0; i < len; i++) {
      if (flag) break;
      if (i == len - 1) {
        multiset<int>::iterator it = st.begin();
        printf("%c\n", (*it) + 'a');
        break;
      }
      if (flag == 0) {
        if (st.count(s2[i] - 'a') > 0) {
          st.erase(st.find(s2[i] - 'a'));
          if (gao(i + 1) == 1) {
            printf("%c", s2[i]);
            continue;
          } else {
            st.insert(s2[i] - 'a');
            for (int j = s2[i] - 'a' + 1; j < 26; j++) {
              if (st.count(j) > 0) {
                st.erase(st.find(j));
                if (gao(i + 1)) {
                  printf("%c", j + 'a');
                  break;
                } else {
                  st.insert(j);
                }
              }
            }
            multiset<int>::iterator it;
            for (it = st.begin(); it != st.end(); it++) {
              printf("%c", (*it) + 'a');
            }
            printf("\n");
            flag = 1;
          }
        } else {
          for (int j = s2[i] - 'a' + 1; j < 26; j++) {
            if (st.count(j) > 0) {
              st.erase(st.find(j));
              if (gao(i)) {
                printf("%c", j + 'a');
                break;
              } else {
                st.insert(j);
              }
            }
          }
          multiset<int>::iterator it;
          for (it = st.begin(); it != st.end(); it++) {
            printf("%c", (*it) + 'a');
          }
          printf("\n");
          flag = 1;
        }
      }
    }
  }
  return 0;
}
