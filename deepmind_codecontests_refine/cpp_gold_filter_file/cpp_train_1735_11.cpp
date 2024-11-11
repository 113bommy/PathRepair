#include <bits/stdc++.h>
using namespace std;
const long long NR = 2e5 + 100;
const long long oo = 2e9 + 100;
const long long MOD = 998244353;
map<long long, long long> mapp;
bool cmp(long long i, long long j) {
  long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
  while (i % 3 == 0) {
    i /= 3;
    ans1++;
  }
  while (i % 2 == 0) {
    i /= 2;
    ans3++;
  }
  while (j % 3 == 0) {
    j /= 3;
    ans2++;
  }
  while (j % 2 == 0) {
    j /= 2;
    ans4++;
  }
  return (ans1 > ans2) || (ans1 == ans2 && ans3 < ans4);
}
long long a[NR];
signed main() {
  long long n, i, x;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> x;
    a[i] = x;
    mapp[x] = 1;
  }
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  return 0;
}
