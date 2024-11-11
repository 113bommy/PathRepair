#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << -1 << endl;
    } else {
      vector<int> v{3, 1, 2, 4};
      int counter = 0;
      for (int i = 5; i <= n; i++) {
        if (counter == 0) {
          counter = 1;
          v.push_back(i);
        } else {
          counter = 0;
          v.insert(v.begin(), i);
        }
      }
      for (int i = 0; i < n; i++) cout << v[i] << " ";
      cout << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
