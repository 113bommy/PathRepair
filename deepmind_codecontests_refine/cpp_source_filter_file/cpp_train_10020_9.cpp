#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int deg_x = 0;
    for (int i = 0; i < n - 1; i++) {
      int temp1, temp2;
      cin >> temp1 >> temp2;
      if (temp1 == x || temp2 == x) {
        deg_x++;
      }
    }
    if (deg_x == 1) {
      cout << "Ayush"
           << "\n";
      continue;
    }
    if ((n - 2) & 1)
      cout << "Ashish\n";
    else
      cout << "Ayush\n";
  }
  return 0;
}
