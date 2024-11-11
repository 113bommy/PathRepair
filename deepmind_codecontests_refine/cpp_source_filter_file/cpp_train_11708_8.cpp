#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1 << 4];
int b[1 << 4];
char buf[1 << 6];
int cnt[1 << 18];
map<long long, int> M;
int main() {
  for (int i = 0; i < 1 << 18; ++i) {
    int x = i;
    while (x) {
      cnt[i]++;
      x &= x - 1;
    }
  }
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%s", buf);
    for (int j = 0; j < n; ++j) a[i] |= ((long long)(buf[j] == '1')) << j;
    scanf("%d", &b[i]);
  }
  int n1 = n / 2;
  int n2 = n - n / 2;
  for (int i = 0; i < 1 << n1; ++i) {
    long long val = 0;
    bool bad = 0;
    for (int j = 0; j < m; ++j) {
      int right = n1 - cnt[(a[j] & ((1 << n1) - 1)) ^ i];
      if (right > b[j]) bad = 1;
      val = val * 8 + (b[j] - right);
    }
    if (bad) continue;
    M[val]++;
  }
  long long res = 0;
  for (int i = 0; i < 1 << n2; ++i) {
    long long val = 0;
    bool bad = 0;
    for (int j = 0; j < m; ++j) {
      int right = n1 - cnt[(a[j] >> n1) ^ i];
      if (right > b[j]) bad = 1;
      val = val * 8 + right;
    }
    if (bad) continue;
    res += M[val];
  }
  printf("%I64d\n", res);
  return 0;
}
