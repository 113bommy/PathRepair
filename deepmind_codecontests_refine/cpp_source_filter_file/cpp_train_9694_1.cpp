#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long n, inf, ans = 0;
  string pol;
  vector<set<int> > a(4);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pol >> inf;
    if (pol == "11")
      a[0].insert(-inf);
    else if (pol == "10")
      a[1].insert(-inf);
    else if (pol == "01")
      a[2].insert(-inf);
    else
      a[3].insert(-inf);
  }
  for (auto it = a[0].begin(); it != a[0].end(); it++) ans += *it;
  for (; !a[1].empty() && !a[2].empty();) {
    ans += *a[1].begin() + *a[2].begin();
    a[1].erase(a[1].begin());
    a[2].erase(a[2].begin());
  }
  int A = 1;
  if (!a[A].empty()) {
    for (auto it = a[A].begin(); it != a[A].end(); it++) a[3].insert(*it);
  }
  A = 2;
  if (!a[A].empty()) {
    for (auto it = a[A].begin(); it != a[A].end(); it++) a[3].insert(*it);
  }
  int i = 0;
  for (auto it = a[3].begin(); i < a[0].size() && i < a[3].size(); i++, it++) {
    ans += *it;
  }
  cout << (0 - ans);
  return 0;
}
