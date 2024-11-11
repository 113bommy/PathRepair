#include <bits/stdc++.h>
using namespace std;
int t, n, x;
vector<int> v[1001];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
    }
    for (int i = 1, a, b; i < n; ++i) {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    if (v[x].size() == 1 || (n - 2) % 2 == 0 || n == 0) {
      cout << "Ayush" << endl;
    } else {
      cout << "Ashish" << endl;
    }
  }
  return 0;
}
