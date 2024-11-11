#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ia = 0, ib = 0;
  bool pos = false;
  while (ia < a.size() && ib < b.size()) {
    if (a[ia] <= b[ib]) {
      ia++;
      ib++;
      continue;
    }
    while (ib < b.size() && a[ia] > b[ib]) {
      ib++;
      pos = true;
    }
    ia++;
  }
  if (ia >= a.size() && ib >= b.size()) {
    cout << (pos ? "YES" : "NO");
  } else if (ia < a.size()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
