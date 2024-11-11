#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    int total = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
      total += vec[i];
      maxi = max(maxi, vec[i]);
    }
    if (maxi > total / 2) {
      cout << "T";
    } else {
      if (n & 1) {
        cout << "T";
      } else {
        cout << "HL";
      }
    }
    cout << endl;
  }
}
