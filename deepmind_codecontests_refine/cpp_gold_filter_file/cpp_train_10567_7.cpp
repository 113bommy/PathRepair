#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
string s;
int m, l[N], r[N], k[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> s >> m;
  int n = s.length();
  string temp;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> k[i];
    l[i]--, r[i]--;
    k[i] %= (r[i] - l[i] + 1);
    temp = s.substr(0, l[i]) + s.substr(r[i] - k[i] + 1, k[i]) +
           s.substr(l[i], r[i] - l[i] + 1 - k[i]) +
           s.substr(r[i] + 1, n - r[i] - 1);
    s = temp;
  }
  cout << s;
  return 0;
}
