#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << m * (m - 1) / 2 << "\n";
  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
      if (k)
        cout << j + 1 << " " << i + 1 << "\n";
      else
        cout << i + 1 << " " << j + 1 << "\n";
    }
  }
}
