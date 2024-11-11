#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int l[m], r[m];
  char c1[m], c2[m];
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> c1[i] >> c2[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = l[i]; j < r[i] + 1; j++) {
      if (s[j] == c1[i]) {
        s[j] = c2[i];
      }
    }
  }
  cout << s << endl;
  return 0;
}
