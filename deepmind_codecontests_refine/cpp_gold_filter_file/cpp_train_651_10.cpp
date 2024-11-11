#include <bits/stdc++.h>
using namespace std;
long long int arr[1000000 + 5];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int tableNumber = 4 * n;
    for (int i = 1; i <= n; i++) {
      cout << tableNumber << " ";
      tableNumber -= 2;
    }
    cout << endl;
  }
  return 0;
}
