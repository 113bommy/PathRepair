#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void debugi(vector<int>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugl(vector<ll>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugmap(map<int, int>& mp) {
  for (auto x : mp) {
    cout << x.first << " " << x.second << " , ";
  }
  cout << endl;
}
void debugset(set<int>& st) {
  for (auto x : st) {
    cout << x << " ";
  }
  cout << endl;
}
void debugparri(vector<pair<int, int>>& arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    cout << "[" << arr[i].first << " : " << arr[i].second << "]"
         << " ";
  }
  cout << endl;
}
void debugpi(pair<int, int>& pi) {
  cout << pi.first << " " << pi.second << endl;
}
void debugq(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
bool check(int n, int i, int j) {
  if ((0 <= i & i < n) && (0 <= j & j < n)) {
    return true;
  }
  return false;
}
ll powab(ll a, ll b, ll mod) {
  if (b == 0) {
    return 1;
  }
  ll z = powab(a, b / 2, mod);
  ll res = (z * z * 1LL) % mod;
  if (b & 1) {
    res = (res * 1LL * a) % mod;
  }
  return res;
}
void upd(int k, int x, vector<int>& tree, int n) {
  if (k == 0) {
    return;
  }
  while (k <= n) {
    tree[k] += x;
    k += (k & -k);
  }
}
int sum(int k, vector<int>& tree, int n) {
  int s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= (k & -k);
  }
  return s;
}
char s[100006];
int m = 200005;
int p;
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
ll ans = 0;
ll mod = 1000000007;
vector<ll> arr(100006);
vector<vector<int>> tree(100006);
vector<ll> cur;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    ll m, d, w, dc, wc;
    cin >> m >> d >> w;
    dc = d;
    wc = w;
    map<int, int> mpd, mpw;
    for (int i = 2; i * i <= d; i++) {
      if (dc % i == 0) {
        int cnt = 0;
        while (dc % i == 0) {
          dc /= i;
          cnt += 1;
        }
        mpd[i] = cnt;
      }
    }
    if (dc != 1) {
      mpd[dc] += 1;
    }
    for (int i = 2; i * i <= w; i++) {
      if (wc % i == 0) {
        int cnt = 0;
        while (wc % i == 0) {
          wc /= i;
          cnt += 1;
        }
        mpw[i] = cnt;
      }
    }
    if (wc != 1) {
      mpw[wc] += 1;
    }
    for (auto x : mpw) {
      if (mpd.find(x.first) != mpd.end()) {
        mpw[x.first] = max(0, mpw[x.first] - mpd[x.first]);
      }
    }
    ll num = 1;
    for (auto x : mpw) {
      if (x.second != 0) {
        for (int j = 0; j < x.second; j++) {
          num *= x.first;
        }
      }
    }
    ll y = min(d, m);
    ll lim = y / num;
    ll x = y % num;
    ll ans = 0;
    ans += (x * lim) * 1LL;
    ans += (num) * (lim - 1) * (lim) / 2 * 1LL;
    cout << ans << endl;
  }
}
