#include <bits/stdc++.h>
using namespace std;
const bool debug = 1;
const int maxn = 2 * 1e5 + 100;
int T;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    int n, m, a, b;
    cin >> n >> m;
    n *= 3;
    vector<bool> used;
    used.resize(n);
    vector<int> matching;
    vector<int> ind_set;
    for (int i = 1; i <= m; i++) {
      cin >> a >> b;
      if (!(used[a] || used[b])) {
        matching.push_back(i);
        used[a] = 1;
        used[b] = 1;
      } else
        ind_set.push_back(i);
    }
    if (matching.size() >= n / 3) {
      cout << "Matching\n";
      for (int i = 0; i < n / 3; i++) cout << matching[i] << " ";
      cout << "\n";
    } else {
      int count = 0;
      cout << "IndSet\n";
      for (int i = 1; i <= n; i++) {
        if (!used[i]) {
          count++;
          cout << i << " ";
          if (count == n / 3) break;
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
