#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    int aux;
    cin >> aux;
    c1 += aux == 1;
    c2 += aux == -1;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if ((a - b + 1) % 2 == 0) {
      if (c1 >= (a - b + 1) / 2 && c2 >= (a - b + 1) / 2)
        cout << "1\n";
      else
        cout << "0\n";
    } else
      cout << "0\n";
  }
  return 0;
}
