#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x;
  set<int> asd;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> x;
      asd.insert(x);
    }
  }
  if (asd.size() == m)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
