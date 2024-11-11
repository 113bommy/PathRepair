#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      maxi = max(maxi, abs(vec[i] - (i + 1)));
    }
    cout << maxi << '\n';
  }
  return 0;
}
