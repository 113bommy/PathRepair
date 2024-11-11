#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, i;
  cin >> n >> k;
  string name;
  cin >> name;
  if (n - k > k - 1) {
    for (i = 1; i <= k - 1; i++) cout << "LEFT\n";
    for (i = 0; i < n - 1; i++) {
      cout << "PRINT " << name[i] << "\n"
           << "RIGHT\n";
    }
    cout << "PRINT ";
    cout << name[i] << endl;
  } else {
    for (i = 1; i <= n - k; i++) cout << "RIGHT\n";
    for (i = n - 1; i > 0; i--) {
      cout << "PRINT " << name[i] << "\n"
           << "LEFT\n";
    }
    cout << "PRINT ";
    cout << name[i] << endl;
  }
}
