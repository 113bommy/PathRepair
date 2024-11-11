#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long n, a[N], c, el;
map<long long, long long> mp;
void winner(bool x) {
  !x ? cout << "sjfnb" : cout << "cslnb";
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (auto& p : mp) {
    if (p.second == 2) {
      c++;
      el = p.first;
    } else if (p.second > 2)
      winner(1);
  }
  if (c >= 2)
    winner(1);
  else if (c == 1 && (mp[el - 1] || !el))
    winner(1);
  else {
    sort(a, a + n);
    c = 0;
    for (long long i = 0; i < n; ++i) c += a[i] - i;
    winner((c + 1) & 1);
  }
}
