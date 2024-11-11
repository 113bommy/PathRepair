#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x;
    vector<int> odd, even;
    for (int i = 0; i < n * 2; i++) {
      cin >> x;
      if (x % 2)
        odd.push_back(x);
      else
        even.push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
      if (odd.size() >= 2) {
        cout << odd[0] << " " << odd[1] << "\n";
        odd.erase(odd.begin(), odd.begin() + 2);
      } else {
        cout << even[0] << " " << even[1] << "\n";
        even.erase(even.begin(), even.begin() + 2);
      }
    }
  }
}
