#include <bits/stdc++.h>
using namespace std;
int t;
int n;
vector<int> prm;
const int N = 1e6 + 1;
int u[N];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  memset(u, 0, sizeof(u));
  prm.clear();
  for (int i = 3; i < N; i += 2) {
    if (u[i] == 0) {
      prm.push_back(i);
      for (int j = 3; i * j < N; j += 2) u[i * j] = 1;
    }
  }
  while (cin >> t) {
    while (t--) {
      cin >> n;
      if (n < 4) {
        cout << n << '\n';
        continue;
      }
      int a1 = upper_bound(prm.begin(), prm.end(), n) - prm.begin();
      n = n / 3;
      int a2 = upper_bound(prm.begin(), prm.end(), n) - prm.begin();
      cout << a1 - a2 + 1 << '\n';
    }
  }
  return 0;
}
