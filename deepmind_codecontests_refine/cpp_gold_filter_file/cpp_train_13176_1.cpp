#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string pl[n];
  string en[m];
  if (n > m)
    cout << "YES";
  else if (m > n)
    cout << "NO";
  else {
    set<string> s;
    int ile = 0;
    for (int i = 0; i < n; i++) {
      cin >> pl[i];
      s.insert(pl[i]);
    }
    for (int i = 0; i < m; i++) {
      cin >> en[i];
      if (s.count(en[i])) ile ^= 1;
    }
    if (ile)
      cout << "YES";
    else
      cout << "NO";
  }
}
