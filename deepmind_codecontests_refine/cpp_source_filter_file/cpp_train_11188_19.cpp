#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<string, string> m;
  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (m[b] != "")
      m[b] = m[a];
    else
      m[b] = a;
    m.erase(a);
  }
  cout << m.size() << '\n';
  for (auto i : m) {
    cout << i.second << ' ';
    cout << i.first << '\n';
  }
}
