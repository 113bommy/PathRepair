#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, int> nesto;
    int res = 0;
    vector<int> niz(n);
    vector<int> sta = niz;
    for (int i = 0; i < n; i++) {
      cin >> niz[i];
      sta[i] = niz[i];
    }
    sort(niz.begin(), niz.end());
    auto gde = unique(niz.begin(), niz.end());
    for (int i = 0; i < n; i++) {
      int a = sta[i];
      a = lower_bound(niz.begin(), gde, a) - niz.begin();
      nesto[a] = max(nesto[a - 1] + 1, nesto[a] + 1);
      res = max(res, nesto[a]);
    }
    cout << n - res << "\n";
  }
  return 0;
}
