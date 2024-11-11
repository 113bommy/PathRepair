#include <bits/stdc++.h>
using namespace std;
char ch[105];
int num[30];
int q[205];
vector<int> v;
int main() {
  int T;
  int len;
  int a, b;
  scanf("%d", &T);
  while (T--) {
    v.clear();
    memset(q, -1, sizeof(q));
    memset(num, 0, sizeof(num));
    scanf("%s", ch);
    len = strlen(ch);
    for (int i = 0; i < len; i++) num[ch[i] - 'a']++;
    for (int i = 0; i < 26; i++)
      if (num[i] != 0) v.push_back(i);
    if (v.size() == 2) {
      if (v[0] == v[1])
        printf("No answer\n");
      else {
        int x = v[0];
        while (num[x]) {
          printf("%c", 'a' + x);
          num[x]--;
        }
        x = v[1];
        while (num[x]) {
          printf("%c", 'a' + x);
          num[x]--;
        }
        printf("\n");
      }
    } else if (v.size() == 3) {
      if (v[0] + 1 == v[1] && v[1] + 1 == v[2])
        printf("No answer\n");
      else {
        int q, w, r;
        if (v[0] + 1 == v[1])
          q = v[0], w = v[2], r = v[1];
        else if (v[1] + 1 == v[2])
          q = v[1], w = v[0], r = v[2];
        else
          q = v[0], w = v[1], r = v[2];
        int x;
        x = q;
        while (num[x]) {
          printf("%c", 'a' + x);
          num[x]--;
        }
        x = w;
        while (num[x]) {
          printf("%c", 'a' + x);
          num[x]--;
        }
        x = r;
        while (num[x]) {
          printf("%c", 'a' + x);
          num[x]--;
        }
        printf("\n");
      }
    } else if (v.size() == 1) {
      int x = v[0];
      while (num[x]) {
        printf("%c", 'a' + x);
        num[x]--;
      }
      printf("\n");
      continue;
    } else {
      int x = v[0];
      int siz = v.size();
      q[100] = v[0];
      q[101] = v[siz - 1];
      q[99] = v[siz - 2];
      a = 98;
      b = 102;
      if (siz % 2) {
        for (int i = 1; i < siz - 2; i++) {
          if (i % 2)
            q[a--] = v[i];
          else
            q[b++] = v[i];
        }
      } else {
        for (int i = 1; i < siz - 2; i++) {
          if (i % 2)
            q[b++] = v[i];
          else
            q[a--] = v[i];
        }
      }
      for (int i = 0; i < 200; i++) {
        if (q[i] == -1)
          continue;
        else {
          x = q[i];
          while (num[x]) {
            printf("%c", 'a' + x);
            num[x]--;
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
