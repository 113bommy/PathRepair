#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20) + 5;
int a[200060];
set<int> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int k, n, m;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (k == 1) return cout << n << endl, 0;
  sort(a, a + n);
  int p = 1;
  s.insert(0);
  auto it = s.begin();
  int j = 1;
  for (int i = 1; i < n; i++) {
    if (p < k - 1) {
      s.insert(i);
      j = i + 1;
      ++p;
    } else {
      while (a[i] - a[*it] < m) ++i;
      if (i >= n) break;
      s.insert(i);
      it++;
    }
  }
  cout << n - s.size() << endl;
  return 0;
}
