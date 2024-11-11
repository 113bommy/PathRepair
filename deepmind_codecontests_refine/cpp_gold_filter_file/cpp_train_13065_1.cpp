#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, C = 0, y;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x >> y;
      if (x || y) C++;
    }
  }
  cout << C << endl;
}
