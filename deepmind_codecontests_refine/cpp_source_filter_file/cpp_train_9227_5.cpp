#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
pair<int, int> w[maxn + 1];
bool solve(int n, int s1, int s2, int type) {
  sort(w + 1, w + 1 + n);
  for (int i = 1; i <= n; ++i) {
    int sz1 = s1 / w[i].first + (s1 % w[i].first != 0);
    if (sz1 >= n) continue;
    int sz2 = n - sz1 - (i - 1);
    if (s1 <= 0 || sz2 <= 0) break;
    if ((double)s2 / sz2 <= (double)w[sz1 + i].first) {
      cout << "Yes\n";
      if (type == 1) {
        cout << sz1 << " " << sz2 << "\n";
        for (int k = i; k < sz1 + i; ++k) cout << w[k].second << " ";
        cout << "\n";
        for (int k = sz1 + i; k <= sz1 + i + sz2 - 1; ++k)
          cout << w[k].second << " ";
      } else {
        cout << sz2 << " " << sz1 << "\n";
        for (int k = sz1 + i; k <= sz1 + i + sz2 - 1; ++k)
          cout << w[k].second << " ";
        cout << "\n";
        for (int k = i; k < sz1 + i; ++k) cout << w[k].second << " ";
      }
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i].first;
    w[i].second = i;
  }
  if (!solve(n, s1, s2, 1))
    if (!solve(n, s2, s1, 2)) cout << "No";
}
