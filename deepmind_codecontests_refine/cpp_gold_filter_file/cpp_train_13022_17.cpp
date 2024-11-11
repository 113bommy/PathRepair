#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int li, ri;
  cin >> n >> m;
  bool mass[m + 1];
  for (int i = 1; i <= m; i++) mass[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> li >> ri;
    for (int j = li; j <= ri; j++) {
      mass[j] = 1;
    }
  }
  int c = 0;
  for (int i = 1; i <= m; i++) {
    if (mass[i] == 0) c++;
  }
  cout << c << endl;
  for (int i = 1; i <= m; i++) {
    if (mass[i] == 0) cout << i << " ";
  }
  return 0;
}
