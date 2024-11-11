#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
const int inf = 2000000000;
const long long int infLL = (long long int)1e18;
long long int MOD = 1000000007;
int MOD1 = 1000000007;
int MOD2 = 1000000009;
inline bool checkBit(long long int n, long long int i) {
  return n & (1LL << i);
}
inline long long int setBit(long long int n, long long int i) {
  return n | (1LL << i);
  ;
}
inline long long int resetBit(long long int n, long long int i) {
  return n & (~(1LL << i));
}
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long int &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long int modMul(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long int modSub(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long int modPow(long long int b, long long int p) {
  long long int r = 1LL;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long int modDiv(long long int a, long long int b) {
  return modMul(a, modPow(b, MOD - 2));
}
bool comp(const pair<long long int, pair<long long int, long long int> > &p1,
          const pair<long long int, pair<long long int, long long int> > &p2) {
  return p1.first > p2.first;
}
bool comp1(const pair<long long int, long long int> &p1,
           const pair<long long int, long long int> &p2) {
  if (p1.first == p2.first) {
    return p1.second > p2.second;
  }
  return p1.first < p2.first;
}
long long int converter(string a) {
  long long int i, mul = 1LL, r, t, ans = 0LL;
  if (a.length() == 0) return 0;
  for (i = a.length() - 1; i >= 0; i--) {
    t = a[i] - '0';
    r = t % 10;
    ans += (mul * r);
    mul = mul * 10;
  }
  return ans;
}
int msb(unsigned x) {
  union {
    double a;
    int b[2];
  };
  a = x;
  return (b[1] >> 20) - 1023;
}
const int MAX = 1005;
int n, k, vis[MAX], what;
vector<long long int> adj[MAX];
int ask(int l, int r) {
  vector<long long int> store;
  for (int i = l; i <= r; ++i) store.push_back(i);
  cout << "? " << store.size();
  for (int i = l; i <= r; ++i) {
    cout << " " << i;
  }
  cout << '\n';
  fflush(stdout);
  int maxi;
  cin >> maxi;
  return maxi;
}
int maxIndex(int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  int cur = ask(l, mid);
  if (cur == what)
    return maxIndex(l, mid);
  else
    return maxIndex(mid + 1, r);
}
void printt(int bad, int ans) {
  cout << "!";
  for (int i = 1; i <= k; ++i) {
    if (i == bad) {
      cout << " " << ans;
    } else
      cout << " " << what;
  }
  cout << '\n';
  fflush(stdout);
  string s;
  cin >> s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int bad = -1, ans, c, x, f;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i <= k; ++i) {
      cin >> c;
      for (int j = 1; j <= c; ++j) {
        cin >> x;
        adj[i].push_back(x);
      }
    }
    what = ask(1, n);
    int idx = maxIndex(1, n);
    for (int i = 1; i <= k; ++i) {
      f = 0;
      memset(vis, 0, sizeof(vis));
      c = adj[i].size();
      for (int j = 1; j <= c; ++j) {
        x = adj[i][j - 1];
        vis[x] = true;
        f |= (x == idx);
      }
      if (f == 1) {
        vector<long long int> temp;
        for (int j = 1; j <= n; ++j)
          if (!vis[j]) {
            temp.push_back(j);
          }
        cout << "? " << temp.size();
        for (int j = 0; j < temp.size(); ++j) cout << " " << temp[j];
        cout << '\n';
        fflush(stdout);
        cin >> ans;
        bad = i;
      }
    }
    printt(bad, ans);
  }
  return 0;
}
