#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, fa[maxn], ans;
bool v[maxn];
pair<pair<int, int>, int> P[maxn];
int getanc(int x) { return fa[x] < 0 ? x : fa[x] = getanc(fa[x]); }
inline void merge(int x, int y) { fa[x] = getanc(y); }
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> P[i].first.second >> P[i].first.first,
        P[i].first.second = n + 1 - P[i].first.second, P[i].second = i;
  sort(P, P + m);
  memset(fa, 255, sizeof(fa));
  for (int i = 0; i < m; i++) {
    int x = getanc(P[i].first.second);
    if (x <= P[i].first.first && x <= n)
      v[P[i].second] = true, ans++, merge(x, x + 1);
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++)
    if (v[i]) cout << i + 1 << ' ';
  cout << endl;
  return 0;
}
