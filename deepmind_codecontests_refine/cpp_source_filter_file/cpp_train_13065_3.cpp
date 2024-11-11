#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, suma{};
  cin >> n >> m;
  while (n--) {
    vector<int> arr(2 * m);
    for (int i = 0; i < 2 * m; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i <= m + 1; i += 2) {
      if (arr[i] == 1 or arr[i + 1] == 1) {
        suma++;
      }
    }
  }
  cout << suma << endl;
}
