#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    set<long long int> s;
    vector<int> v(n);
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      s.insert(v[i]);
      umap[v[i]]++;
    }
    if (n == 1)
      cout << 0 << endl;
    else {
      int unique = s.size();
      int max1 = INT_MIN;
      for (auto x : umap) {
        max1 = max(max1, x.second);
      }
      if (unique > max1) {
        cout << max1 << endl;
      } else if (max1 > unique) {
        cout << max1 - 1 << endl;
      } else
        cout << unique - 1 << endl;
    }
  }
}
