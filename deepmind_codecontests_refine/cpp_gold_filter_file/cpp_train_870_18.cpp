#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int m, a, b;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a - 2 >= 0) {
      arr[a - 2] += b - 1;
    }
    if (a != n) {
      arr[a] += arr[a - 1] - b;
    }
    arr[a - 1] = 0;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}
