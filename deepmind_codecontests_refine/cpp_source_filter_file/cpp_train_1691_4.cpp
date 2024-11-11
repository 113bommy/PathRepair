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
    vector<int> v(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      pos[v[i]] = i;
    }
    auto pi = v.begin() + pos[1];
    bool possible = true;
    for (int i = 2; i <= n; i++) {
      auto index = v.begin() + pos[2];
      if (index > pi && index != pi + 1) {
        possible = false;
        break;
      }
      pi = index;
    }
    if (possible)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
