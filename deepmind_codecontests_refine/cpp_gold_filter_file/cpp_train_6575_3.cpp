#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 3;
long long n, k, a[N], res = 0;
pair<long long, long long> s[N];
vector<long long> x;
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i > 0; i--) {
    s[i].first = s[i + 1].first + a[i];
    s[i].second = i;
  }
  res += s[1].first;
  sort(s + 2, s + n + 1);
  for (int i = n; i > n - k + 1; i--) {
    res += s[i].first;
  }
  cout << res;
}
