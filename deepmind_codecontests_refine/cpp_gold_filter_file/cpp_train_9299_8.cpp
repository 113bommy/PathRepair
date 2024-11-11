#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, q;
int G = 1;
int ss[N];
int b[N];
int tim;
int tin[N];
int tout[N];
int use[N];
int t[4 * N];
map<int, int> f[N];
vector<int> v[N];
void dfs(int x, int p) {
  tin[x] = ++tim;
  for (auto y : v[x]) {
    if (y != p) {
      dfs(y, x);
    }
  }
  tout[x] = tim;
}
void upd(int x, int val) {
  while (x < N) {
    t[x] += val;
    x += x & -x;
  }
}
long long get(int x) {
  long long res = 0;
  while (x > 0) {
    res += t[x];
    x -= x & -x;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> q >> n;
  for (int i = 0; i < 26; i++) f[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;
    int st = 1;
    for (int j = 0; j < (int)t.size(); j++) {
      int c = t[j] - 'a';
      if (f[st].find(c) == f[st].end()) {
        f[st][c] = ++G;
      }
      st = f[st][c];
    }
    b[i] = st;
  }
  queue<int> q1;
  q1.push(1);
  while (!q1.empty()) {
    int x = q1.front();
    q1.pop();
    for (auto y : f[x]) {
      q1.push(y.second);
      int xx = ss[x];
      while (f[xx].find(y.first) == f[xx].end()) {
        xx = ss[xx];
      }
      xx = f[xx][y.first];
      ss[y.second] = xx;
    }
  }
  for (int i = 2; i <= G; i++) {
    v[i].push_back(ss[i]);
    v[ss[i]].push_back(i);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    upd(tin[b[i]], 1);
    upd(tout[b[i]] + 1, -1);
  }
  while (q--) {
    string tt;
    cin >> tt;
    if (tt[0] == '?') {
      long long sum = 0;
      int st = 1;
      for (int i = 1; i < (int)tt.size(); i++) {
        int x = tt[i] - 'a';
        while (f[st].find(x) == f[st].end()) {
          st = ss[st];
        }
        st = f[st][x];
        sum += get(tin[st]);
      }
      cout << sum << "\n";
    } else {
      int x = 0;
      for (int i = 1; i < (int)tt.size(); i++) {
        x = x * 10 + (tt[i] - '0');
      }
      if (tt[0] == '-' && !use[x]) {
        use[x] = 1;
        x = b[x];
        upd(tin[x], -1);
        upd(tout[x] + 1, 1);
      } else if (tt[0] == '+' && use[x]) {
        use[x] = 0;
        x = b[x];
        upd(tin[x], 1);
        upd(tout[x] + 1, -1);
      }
    }
  }
}
