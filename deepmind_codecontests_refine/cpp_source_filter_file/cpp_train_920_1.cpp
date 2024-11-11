#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int) n; i++)

ll n, x;
vector<ll> a, mi;

ll calc(int pos)
{
  ll res = 0;
  rep(i, n) mi[i] = min(mi[i], a[(i+pos)%n]);
  rep(i, n) res+= mi[i];
  return res + pos * x;
}

int main()
{
  cin >> n >> x;
  rep(i, n) {
    ll t;
    cin >> t;
    a.push_back(t);
    mi.push_back(t);
  }
  ll res = INF;
  rep(i, n) {
    res = min(res, calc(i));
  }
  cout << res << endl;
}