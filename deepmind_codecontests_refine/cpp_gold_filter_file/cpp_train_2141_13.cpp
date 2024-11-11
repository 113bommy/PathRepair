#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
char ss[N];
int aa[N];
vector<int> vv;
int num[30];
int llog2[N];
void init() {
  llog2[1] = 0;
  int ans = 2;
  for (int i = 2; i < N; i++) {
    if (i == ans) {
      ans *= 2;
      llog2[i] = llog2[i - 1] + 1;
    } else {
      llog2[i] = llog2[i - 1];
    }
  }
}
int main() {
  int n, m;
  while (scanf("%d", &m) != EOF) {
    scanf("%s", ss);
    n = strlen(ss);
    for (int i = 0; i < n; i++) {
      aa[i] = ss[i] - 'a';
    }
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 26; i++) {
      vv.clear();
      int pre = -1;
      int flag = 1;
      for (int j = 0; j < n; j++)
        if (aa[j] <= i) {
          vv.push_back(j);
          if (pre == -1) {
            if (j >= m) {
              flag = 0;
              break;
            }
          } else {
            if (j - pre - 1 >= m) {
              flag = 0;
              break;
            }
          }
          pre = j;
        }
      if (n - 1 - pre >= m) flag = 0;
      pre = -1;
      if (flag == 1) {
        for (int j = 0; j < vv.size(); j++) {
          int jj = vv[j];
          if (aa[jj] < i) {
            pre = jj;
            num[aa[jj]]++;
          } else {
            if (pre == -1) {
              if (j == vv.size() - 1) {
                pre = jj;
                num[aa[jj]]++;
              } else {
                int jjj = vv[j + 1];
                if (jjj >= m) {
                  pre = jj;
                  num[aa[jj]]++;
                }
              }
            } else {
              if (n - 1 - pre < m) continue;
              if (j == vv.size() - 1) {
                pre = jj;
                num[aa[jj]]++;
              } else {
                int jjj = vv[j + 1];
                if (jjj - pre - 1 >= m) {
                  pre = jj;
                  num[aa[jj]]++;
                }
              }
            }
          }
        }
        break;
      }
    }
    for (int i = 0; i < 26; i++) {
      while (num[i]) {
        printf("%c", i + 'a');
        num[i]--;
      }
    }
    printf("\n");
  }
  return 0;
}
