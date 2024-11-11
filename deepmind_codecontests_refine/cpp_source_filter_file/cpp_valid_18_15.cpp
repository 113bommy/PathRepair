#include <bits/stdc++.h>
using namespace std;
const long long N = 105;
long long n, k;
vector<long long> lst;
vector<pair<long long, long long> > Pair;
bool vs[N];
void in() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) vs[i] = false;
  lst.clear(), Pair.clear();
  for (long long i = 1; i <= k; i++) {
    long long u, v;
    cin >> u >> v;
    vs[u] = vs[v] = true;
    Pair.push_back({min(u, v), max(u, v)});
  }
  for (long long i = 1; i <= 2 * n; i++) {
    if (!vs[i]) lst.push_back(i);
  }
  for (long long i = 0; i < lst.size() / 2; i++)
    Pair.push_back({lst[i], lst[i + lst.size() / 2]});
}
long long getNum(long long u, long long v) {
  long long a = Pair[u].first, b = Pair[u].second;
  long long c = Pair[v].first, d = Pair[v].second;
  if (a < c && c < b && (d > b || d < a)) return 1;
  if (a < d && d < b && (c > b || c < a)) return 1;
  return 0;
}
void process() {
  long long res = 0;
  for (long long i = 0; i < Pair.size(); i++) {
    for (long long j = 0; j < i; j++) {
      res += getNum(i, j);
    }
  }
  cout << res << '\n';
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    in();
    process();
  }
}
