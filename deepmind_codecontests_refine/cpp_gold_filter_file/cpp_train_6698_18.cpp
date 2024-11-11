#include <bits/stdc++.h>
using namespace std;
int n, h, d[100005], k = 0, a, t, i, m[100004], j, l, f = 0;
string g;
int main() {
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> m[i];
  }
  for (i = 0; i < t; i++) {
    cin >> l;
    d[m[i]] = l;
  }
  for (i = 1; i <= t; i++) {
    cout << d[i] << ' ';
  }
}
