#include <bits/stdc++.h>
const long long LINF = 1e18;
const int INF = 1e9;
const int M = 1e9 + 7;
const double EPS = 1e-9;
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  char ch[1000];
  for (int i = 0; i < n; i++) cin >> ch[i];
  for (int i = 0; i < m; i++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int j = l - 1; j < r; j++) {
      if (ch[j] == c1) {
        ch[j] = c2;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ch[i];
  return 0;
}
