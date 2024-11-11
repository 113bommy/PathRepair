#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  set<int> a;
  for (int i = 0; i < n; i++) {
    int aa;
    cin >> aa;
    a.insert(aa);
  }
  set<int> ans;
  int mm = m;
  for (int i = 1; i < mm + 1; i++) {
    if (m < i) break;
    if (a.find(i) == a.end()) {
      ans.insert(i);
      m -= i;
    }
  }
  cout << ans.size() << endl;
  bool first = true;
  for (int t : ans) {
    if (first)
      first = false;
    else
      cout << " ";
    cout << t;
  }
  cout << endl;
}
