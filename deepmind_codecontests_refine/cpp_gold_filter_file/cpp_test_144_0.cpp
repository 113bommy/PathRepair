#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n % m;
  int b = m - a;
  int c = n / m + 1;
  int d = n / m;
  int pos1 = 0;
  int pos2 = a * c;
  for (int z = 0; z < k; z++) {
    for (int i = 0; i < a; i++) {
      cout << c << " ";
      for (int j = pos1 + i * c; j < pos1 + i * c + c; j++)
        cout << (j % n) + 1 << " ";
      cout << "\n";
    }
    for (int i = 0; i < b; i++) {
      cout << d << " ";
      for (int j = pos2 + i * d; j < pos2 + i * d + d; j++)
        cout << (j % n) + 1 << " ";
      cout << "\n";
    }
    pos1 = (pos1 + a * c) % n;
    pos2 = (pos1 + a * c) % n;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
