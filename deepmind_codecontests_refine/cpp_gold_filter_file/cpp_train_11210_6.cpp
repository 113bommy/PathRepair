#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "-1"
         << "\n";
  } else {
    int i = 0;
    int sum = accumulate(begin(a), end(a), 0);
    int k = 0;
    for (i = 0; i < n - 1; ++i) {
      k += a[i];
      if (k != sum - k) {
        break;
      }
    }
    if (i == n - 1) {
      cout << "-1"
           << "\n";
    } else {
      cout << i + 1 << "\n";
      for (int j = 0; j < i + 1; ++j) {
        cout << j + 1 << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
