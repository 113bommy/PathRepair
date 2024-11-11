#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_set<int> s, ns;
    s.reserve(n);
    ns.reserve(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.insert(a);
    }
    int top = *max_element(s.begin(), s.end());
    bool found = false;
    for (int i = 1; i <= top && !found; i++) {
      ns.clear();
      for (int a : s) ns.insert(i ^ a);
      bool good = true;
      if (ns.size() != s.size())
        good = false;
      else
        for (int a : s)
          if (ns.find(a) == ns.end()) good = false;
      if (good) {
        cout << i << '\n';
        found = true;
      }
    }
    if (!found) cout << "-1\n";
  }
  return 0;
}
