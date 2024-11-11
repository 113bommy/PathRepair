#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, p[200005], al[27], cm = 0, a, init;
    string s;
    cin >> n >> m;
    for (int j = 0; j < 27; j++) al[j] = 0;
    for (int j = 0; j < n; j++) p[j] = 0;
    cin >> s;
    for (int j = 0; j < m; j++) {
      cin >> a;
      p[a - 1]++;
    }
    for (int j = 0; j < n; j++) {
      init = s[j] - 97;
      al[init] += m - cm + 1;
      if (p[j] > 0) cm += p[j];
    }
    for (int j = 0; j < 26; j++) cout << al[j] << " ";
    cout << endl;
  }
  return 0;
}
