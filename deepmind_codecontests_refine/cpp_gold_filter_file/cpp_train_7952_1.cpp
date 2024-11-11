#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, x, y, temp;
  vector<int> arr;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    arr.push_back(x);
    arr.push_back(y);
  }
  sort(arr.begin(), arr.end());
  for (i = 1; i <= n; i++) {
    if (!binary_search(arr.begin(), arr.end(), i)) {
      temp = i;
      break;
    }
  }
  cout << n - 1 << "\n";
  for (i = 1; i <= n; i++) {
    if (i != temp) {
      cout << i << " " << temp << "\n";
    }
  }
  return 0;
}
