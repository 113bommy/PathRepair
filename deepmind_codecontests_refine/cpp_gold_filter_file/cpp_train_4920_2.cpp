#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    if (arr[0] < arr[n - 1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
