#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    vector<int> even;
    vector<int> odd;
    int n;
    cin >> n;
    if (n < 3)
      cout << -1 << "\n";
    else {
      if (n % 2) {
        for (int i = n - 1; i > 4; i -= 2) even.push_back(i);
        for (int i = 5; i <= n; i += 2) odd.push_back(i);
      } else {
        for (int i = n; i > 4; i -= 2) even.push_back(i);
        for (int i = 5; i <= n; i += 2) odd.push_back(i);
      }
      for (auto x : even) cout << x << " ";
      cout << 3 << " " << 1 << " " << 4 << " " << 2 << " ";
      for (auto x : odd) cout << x << " ";
      cout << "\n";
    }
  }
}
