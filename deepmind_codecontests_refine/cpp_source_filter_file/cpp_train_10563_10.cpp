#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  vector<string> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    if (a[i].size() < b[i].size()) b[i] = a[i];
  }
  while (n--) {
    cin >> s;
    auto x = find(a.begin(), a.end(), s);
    int t = x - a.begin();
    cout << b[t] << " ";
  }
}
