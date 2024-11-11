#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b;
    for (int i = 1; i <= sqrt(n); i++) {
      if ((n / i) != i) {
        b.push_back(n / i);
      }
      b.push_back(i);
    }
    b.push_back(0);
    sort(b.begin(), b.end());
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); ++i) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
