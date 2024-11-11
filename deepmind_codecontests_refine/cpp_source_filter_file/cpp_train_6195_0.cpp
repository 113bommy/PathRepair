#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int INF = 1e9 + 9;
int n;
int nxt[N], prv[N];
long long v[N], d[N], p[N];
void del(int x) {
  int pr = prv[x];
  int nx = nxt[x];
  nxt[pr] = nx;
  prv[nx] = pr;
}
vector<int> res;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = int(1); i <= int(n); ++i) {
    cin >> v[i] >> d[i] >> p[i];
    nxt[i] = i + 1;
    prv[i] = i - 1;
  }
  for (int ptr = 1; ptr <= n; ptr = nxt[ptr]) {
    res.push_back(ptr);
    for (int i = nxt[ptr], cnt = 0; i <= n && cnt < v[ptr]; i = nxt[i], ++cnt)
      p[i] -= (v[ptr] - cnt);
    int fear = 0;
    for (int i = nxt[ptr]; i <= n; i = nxt[i]) {
      p[i] -= fear;
      if (p[i] < 0) {
        fear += d[i];
        del(i);
      }
    }
  }
  cout << res.size() << "\n";
  for (auto x : res) cout << x << " ";
  cout << "\n";
  return 0;
}
