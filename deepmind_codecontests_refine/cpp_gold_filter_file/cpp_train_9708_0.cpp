#include <bits/stdc++.h>
using namespace std;
vector<int> pr;
void sieve() {
  bitset<3201> prime;
  prime.set();
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= 3200; i++) {
    if (prime[i] == 1) {
      for (int j = i * i; j <= 3200; j += i) prime[j] = 0;
      pr.push_back(i);
    }
  }
}
vector<int> pf;
void p_fac(int n) {
  int ans = 1;
  for (int i = 0; i < pr.size(); i++) {
    int ans = 1;
    while (n % pr[i] == 0) {
      ans *= pr[i];
      n /= pr[i];
    }
    if (ans != 1) pf.push_back(ans);
  }
  if (n != 1) pf.push_back(n);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, a;
  cin >> n;
  vector<pair<int, int>> ans(n);
  sieve();
  for (i = 0; i < n; i++) {
    pf.clear();
    cin >> a;
    p_fac(a);
    if (pf.size() == 1)
      ans[i].first = ans[i].second = -1;
    else {
      ans[i].first = pf[0];
      ans[i].second = a / ans[i].first;
    }
    cout << ans[i].first << ' ';
  }
  cout << '\n';
  for (i = 0; i < n; i++) cout << ans[i].second << ' ';
}
