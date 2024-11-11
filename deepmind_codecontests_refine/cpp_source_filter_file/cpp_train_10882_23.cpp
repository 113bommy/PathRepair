#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> s;
  int n, m;
  cin >> n >> m;
  int a[n], sum = 0;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    s.insert(k);
  }
  vector<int> ll;
  for (int i = 1; i <= 100000; i++) {
    if (i <= m) {
      if (s.find(i) == s.end()) {
        m -= i;
        ll.push_back(i);
      }
    } else {
      break;
    }
  }
  int x = ll.size();
  cout << x << '\n';
  for (int i = 0; i < x; i++) {
    cout << ll[i] << " ";
  }
  return 0;
}
