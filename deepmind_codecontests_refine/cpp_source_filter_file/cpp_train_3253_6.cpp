#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int N = 300005, M = N;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (power(a, b - 1) * a) % 998244353;
  long long q = power(a, b / 2);
  return (q * q) % 998244353;
}
int par[200005];
int siz[200005];
int f(int x) {
  if (par[x] == x) {
    return x;
  } else
    return par[x] = f(par[x]);
}
pair<int, pair<int, int> > edges[200005];
int x[200005];
int n, m, i, k, l, j;
string s;
vector<int> v(n);
bool ok(long long maxi) {
  if (s.substr(0, maxi) == s.substr(s.length() - maxi - 1, maxi)) {
    return true;
  } else {
    return false;
  }
}
vector<int> adj[500005];
void dfs(int x, int p) {
  for (auto& i : adj[x]) {
    if (i != p) {
      dfs(i, x);
    }
  }
}
int main() {
  long long n, m, a, b, tm[200];
  cin >> n >> m;
  long long gra_col[n + 1];
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> v[n + 1];
  long long getchar_unlocked[n + 1];
  for (int i = 0; i < n; ++i) {
    long long col;
    cin >> col;
    getchar_unlocked[i + 1] = col;
    v[col].push_back(i + 1);
  }
  bool flag;
  vector<int> result;
  for (int i = 1; i <= n; ++i) {
    for (auto ne : v[i]) {
      set<int> s;
      for (auto nei : adj[ne]) {
        if (getchar_unlocked[nei] < getchar_unlocked[ne]) {
          s.insert(getchar_unlocked[nei]);
        }
        if (getchar_unlocked[nei] == getchar_unlocked[ne]) {
          flag = 1;
          break;
        }
      }
      if (s.size() != getchar_unlocked[ne] - 1) {
        flag = 1;
        break;
      }
      result.push_back(ne);
    }
  }
  if (flag == 1) {
    cout << -1 << " ";
  } else {
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i] << " ";
    }
  }
}
