#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  string a, b;
  while (t--) {
    cin >> n >> a >> b;
    vector<int> v[50];
    int f = 0, mx = -1, res = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == a[i]) continue;
      if (b[i] < a[i]) f = 1;
      v[a[i] - 'a'].push_back(b[i] - 'a');
      mx = max(mx, b[i] - 'a');
    }
    if (f) {
      cout << -1;
      printf("\n");
      continue;
    }
    for (int i = 0; i <= mx; i++) {
      set<int> s(v[i].begin(), v[i].end());
      if (i == mx)
        res += s.size();
      else {
        int c = 1, rep;
        if (s.size() != 0) res++;
        for (auto i : s) {
          if (c) {
            rep = i;
            c = 0;
          } else {
            v[rep].push_back(i);
          }
        }
      }
    }
    cout << res;
    printf("\n");
  }
}
