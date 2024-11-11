#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, p, q, c = 0;
  map<string, string> a;
  string s, t;
  cin >> n >> m;
  while (m--) {
    cin >> s >> t;
    a[s] = (s.size() <= t.size() ? s : t);
  }
  while (n--) {
    cin >> s;
    cout << a[s] << " ";
  }
}
