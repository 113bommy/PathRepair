#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7, MAXN = 1e5 + 10;
int n, l, r, a[MAXN], b[MAXN];
vector<int> aa, bb;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> l >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (l <= i && i <= r) aa.push_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (l <= i && i <= r) bb.push_back(b[i]);
  }
  for (int i = 1; i < l; ++i)
    if (a[i] != b[i]) {
      cout << "LIE";
      return 0;
    }
  for (int i = r + 1; i <= n; ++i)
    if (a[i] != b[i]) {
      cout << "LIE";
      return 0;
    }
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  if (aa == bb)
    cout << "TRUTH";
  else
    cout << "LIE";
  return 0;
}
