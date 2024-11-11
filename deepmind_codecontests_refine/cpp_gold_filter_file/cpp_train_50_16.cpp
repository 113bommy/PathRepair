#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, t;
  bool r = 1;
  cin >> n >> m;
  vector<bool> mas(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> t;
      mas[t - 1] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (mas[i] == 0) r = 0;
  }
  if (r == 0)
    cout << "NO";
  else
    cout << "YES";
}
