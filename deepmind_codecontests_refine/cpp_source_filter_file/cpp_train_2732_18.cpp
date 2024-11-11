#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int pn;
vector<ll> p;
void prepare() {
  for (int i = 2; i < 1000; ++i) {
    bool flag = false;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      p.push_back(i);
    }
  }
  pn = p.size();
}
ll cnt = 0, up = 1e9;
vector<int> d;
vector<int> dq;
void query(ll x, int i, int j) {
  if (cnt >= 22) {
    return;
  }
  ++cnt;
  cout << "? " << x << endl;
  int res;
  cin >> res;
  if (res > 1) {
    vector<ll> q;
    vector<ll> qt;
    for (int k = i; k < j; ++k) {
      if (res % p[k] == 0) {
        q.push_back(p[k]);
        qt.push_back(p[k]);
      }
    }
    for (int k = 0; k < q.size(); ++k) {
      ll tq = 1;
      while (tq * q[k] <= up / 2) {
        tq *= q[k];
      }
      qt[k] = tq;
    }
    for (int k = 0; k < qt.size(); ++k) {
      ll tmp = 1;
      j = k;
      while (k < qt.size() && tmp <= 1e18 / qt[j]) {
        tmp *= qt[j];
        ++j;
      }
      if (cnt < 22) {
        cout << "? " << tmp << endl;
        cin >> res;
        for (int r = k; r < j; ++r) {
          int cntTmp = 0;
          while (res % q[r] == 0) {
            cntTmp++;
            res /= q[r];
          }
          d.push_back(cntTmp);
          dq.push_back(q[r]);
        }
        ++cnt;
      } else {
        for (int r = k; r < j; ++r) {
          d.push_back(1);
          dq.push_back(q[r]);
        }
      }
      k = j - 1;
    }
  }
  up = 1e9;
  for (int r = 0; r < d.size(); ++r) {
    up /= pow(dq[r], d[r]);
  }
}
void solve() {
  up = 1e9;
  cnt = 0;
  d.clear();
  dq.clear();
  for (int i = 0; i < pn; ++i) {
    int j = i;
    ll res = 1;
    while (j < pn && res <= 1e18 / p[j]) {
      res *= p[j];
      ++j;
    }
    query(res, i, j);
    i = j - 1;
  }
  int ans = 1;
  for (int i = 0; i < d.size(); ++i) {
    ans *= 1 + d[i];
  }
  int check = (d.size() > 0);
  cout << "! " << max(8 + check, ans * 2) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0), cin.tie(0);
  prepare();
  int z;
  cin >> z;
  while (z--) {
    solve();
  }
  return 0;
}
