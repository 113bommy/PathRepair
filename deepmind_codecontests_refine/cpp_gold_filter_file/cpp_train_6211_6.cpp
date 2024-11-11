#include <bits/stdc++.h>
using namespace std;
double n, a[200001];
map<double, int> b;
void solve() {
  for (int i = 1; i <= n; i++) {
    cout << b[a[i]] << " ";
  }
}
int main() {
  double k, l, m, d[3], j = 0;
  int z;
  string s, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    s += '.';
    z = 0;
    t = "";
    for (int j = 0; j < s.size(); j++) {
      if (s[j] >= 48 && s[j] <= 57) {
        t += s[j];
      } else if (t != "") {
        d[z] = stoi(t);
        z++;
        t = "";
      }
    }
    a[i] = (d[0] + d[1]) / d[2];
    b[a[i]]++;
  }
  solve();
}
