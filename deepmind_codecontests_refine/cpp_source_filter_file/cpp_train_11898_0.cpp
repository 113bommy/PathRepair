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
bool comp(const pair<long long int, pair<long long int, long long int>> &p1,
          const pair<long long int, pair<long long int, long long int>> &p2) {
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
const int MAX = 300005;
int n, m, maxi;
map<string, int> id;
set<pair<int, int>> val[MAX];
int now[MAX], ridx[MAX], curMax[MAX];
string text, s;
struct AhoCorasick {
  int N, P;
  vector<vector<int>> next;
  vector<int> failure, out_failure;
  vector<vector<int>> out;
  AhoCorasick() : N(0), P(0) { node(); }
  int node() {
    next.emplace_back(26, 0);
    failure.emplace_back(0);
    out_failure.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }
  int add_pattern(const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][c - 'a']) next[u][c - 'a'] = node();
      u = next[u][c - 'a'];
    }
    out[u].push_back(P);
    return P++;
  }
  void compute() {
    queue<int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front();
      q.pop();
      for (int c = 0; c < 26; ++c) {
        int v = next[u][c];
        if (!v)
          next[u][c] = next[failure[u]][c];
        else {
          failure[v] = u ? next[failure[u]][c] : 0;
          out_failure[v] =
              out[failure[v]].empty() ? out_failure[failure[v]] : failure[v];
          q.push(v);
        }
      }
    }
  }
  int nextState(int u, char c) {
    while (u && !next[u][c - 'a']) u = failure[u];
    u = next[u][c - 'a'];
    return u;
  }
  void match(const string second) {
    int u = 0;
    for (int i = 0; i < second.size(); ++i) {
      char c = second[i];
      u = nextState(u, c);
      for (int v = u; v; v = out_failure[v]) {
        for (auto p : out[v]) {
          maxi = max(maxi, curMax[ridx[p]]);
        }
      }
    }
  }
} ds;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(20);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  cin >> n >> m;
  int pt = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (id.count(s) == 0) {
      id[s] = ++pt;
      ds.add_pattern(s);
      val[pt].insert({now[i], i});
      ridx[i] = pt;
    } else {
      val[id[s]].insert({now[i], i});
      ridx[i] = id[s];
    }
  }
  ds.compute();
  for (int i = 0; i < m; ++i) {
    int tp;
    cin >> tp;
    if (tp == 2) {
      string text;
      cin >> text;
      maxi = -1;
      ds.match(text);
      cout << maxi << '\n';
    } else {
      int idx, what;
      cin >> idx >> what;
      --idx;
      int pos = ridx[idx];
      val[pos].erase({now[idx], idx});
      now[idx] = what;
      val[pos].insert({now[idx], idx});
      curMax[pos] = val[pos].rbegin()->first;
    }
  }
  return 0;
}
