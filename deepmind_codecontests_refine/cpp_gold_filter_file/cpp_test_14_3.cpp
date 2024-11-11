#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    vector<pair<pair<int, int>, int>> res;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      int m = a[i];
      int ind = i;
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[ind]) {
          m = a[j];
          ind = j;
        }
      }
      if (i != ind) {
        int k = a[ind];
        for (int j = ind; j > i; j--) {
          a[j] = a[j - 1];
        }
        a[i] = k;
        res.push_back({{i + 1, ind + 1}, abs(ind - i)});
      }
    }
    cout << res.size() << endl;
    for (auto x : res) {
      cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
  }
}
