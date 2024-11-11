#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a;
  cin >> n;
  cin >> m;
  for (int i = 0, temp = 0; i < m; i++) {
    cin >> a;
    cout << (a + temp) / m;
    cout << "\t";
    temp = (a + temp) % m;
  }
  return 0;
}
