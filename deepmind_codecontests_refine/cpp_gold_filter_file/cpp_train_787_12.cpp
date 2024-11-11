#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
const int MAX_N = (int)3e5 + 17;
const int mod = (int)1e9 + 7 + eps;
int N, M, S, T, K, tp, bk;
int a[MAX_N], vis[MAX_N];
vector<int> v[MAX_N];
void debug(int nCount, ...) {
  va_list argptr;
  va_start(argptr, nCount);
  cout << "debug:";
  for (int i = 0; i < nCount; i++) cout << " " << va_arg(argptr, int);
  putchar('\n');
  va_end(argptr);
}
int main() {
  int kase = 1;
  char s1[MAX_N], s2[MAX_N], s3[MAX_N], s4[MAX_N];
  while (~scanf("%s %s", s1, s2)) {
    int len = strlen(s1);
    memset(s3, 0, len + 1);
    memset(s4, 0, len + 1);
    sort(s1, s1 + len);
    sort(s2, s2 + len);
    int t1 = 0, t2 = len - 1, bk1 = (len - 1) / 2, bk2 = (len + 1) / 2;
    int bk = len - 1;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
      if (tmp > bk) break;
      if (i % 2 == 0) {
        if (s1[t1] >= s2[t2]) {
          s3[bk] = s1[bk1];
          bk--;
          bk1--;
        } else {
          s3[tmp] = s1[t1];
          t1++;
          tmp++;
        }
      } else {
        if (s1[t1] >= s2[t2]) {
          s3[bk] = s2[bk2];
          bk--;
          bk2++;
        } else {
          s3[tmp] = s2[t2];
          t2--;
          tmp++;
        }
      }
    }
    puts(s3);
  }
  return 0;
}
