#include <bits/stdc++.h>
using namespace std;
string s;
int a[10], b[10];
int ret[100010], ret1[100010];
int main() {
  cin >> s;
  int l = s.length();
  memset(a, 0, sizeof a);
  for (int i = 0; i < l; ++i) a[s[i] - '0']++;
  for (int i = 0; i < 10; ++i) b[i] = a[i];
  int k = 0, kk = -1;
  int ww = 0;
  for (int i = 1; i <= 5; ++i) {
    if (!a[i] || !b[10 - i]) continue;
    a[i]--;
    b[10 - i]--;
    int cnt = 0;
    for (int j = 0; j < 10; ++j) {
      if (a[j] < b[9 - j])
        cnt += a[j];
      else
        cnt += b[9 - j];
    }
    a[i]++;
    b[10 - i]++;
    if (cnt > k) {
      k = cnt;
      kk = i;
    }
  }
  int t = 0;
  if (kk != -1) {
    a[kk]--;
    b[10 - kk]--;
    a[0] -= ww;
    b[0] -= ww;
    t = 1;
    ret[0] = kk;
    ret1[0] = 10 - kk;
    for (int i = 0; i < 10; ++i) {
      int j = 0;
      for (; j < a[i] && j < b[9 - i]; ++j) {
        ret[t] = i;
        ret1[t++] = 9 - i;
      }
      a[i] -= j;
      b[9 - i] -= j;
    }
  }
  int zz = a[0];
  if (zz > b[0]) zz = b[0];
  for (int i = 0; i < a[0] - zz; ++i) printf("0");
  for (int i = 1; i < 10; ++i)
    for (int j = 0; j < a[i]; ++j) printf("%d", i);
  for (int i = t - 1; i >= 0; --i) printf("%d", ret[i]);
  for (int i = 0; i < zz + ww; ++i) printf("0");
  printf("\n");
  for (int i = 0; i < b[0] - zz; ++i) printf("0");
  for (int i = 1; i < 10; ++i)
    for (int j = 0; j < b[i]; ++j) printf("%d", i);
  for (int i = t - 1; i >= 0; --i) printf("%d", ret1[i]);
  for (int i = 0; i < zz + ww; ++i) printf("0");
  printf("\n");
}
