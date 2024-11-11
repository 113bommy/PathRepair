#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(42);
const int N = 5e5 + 5;
array<int, 60> operator^(const array<int, 60> &a, const array<int, 60> &b) {
  array<int, 60> c;
  for (int i = 0; i < 60; i++) {
    c[i] = a[i] + b[i];
    if (c[i] >= 3) c[i] -= 3;
  }
  return c;
}
array<int, 60> operator+(const array<int, 60> &a, int b) {
  for (int i = 0; i < 60; i++) printf("%d", a[i]);
  printf("\n");
}
array<int, 60> bd;
map<array<int, 60>, int> mp;
int cnt[N], a[N];
array<int, 60> sum[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  vector<array<int, 60> > num(n);
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j < 60; j++) num[i][j] = rnd() % 3;
  }
  long long ans = 0;
  int l = 0;
  mp[sum[0]]++;
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
    sum[i] = sum[i - 1] ^ num[a[i]];
    while (cnt[a[i]] == 4) {
      cnt[a[l + 1]]--;
      mp[sum[l]]--;
      l++;
    }
    ans = ans + mp[sum[i]];
    mp[sum[i]]++;
  }
  printf("%lld\n", ans);
}
