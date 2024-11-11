#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, x, u, v, i;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<long long> vec[n + 1];
    for (i = 0; i < n - 1; i++) {
      cin >> u >> v;
      vec[u].push_back(v);
      vec[v].push_back(u);
    }
    if (vec[x].size() == 1)
      cout << "Ayush" << endl;
    else {
      if ((n - 3) % 2)
        cout << "Ayush" << endl;
      else
        cout << "Ashish" << endl;
    }
  }
  return 0;
}
