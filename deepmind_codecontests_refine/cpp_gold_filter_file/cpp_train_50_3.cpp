#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, v;
  set<int> asd;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> v;
      asd.insert(v);
    }
  }
  if (asd.size() == m)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
