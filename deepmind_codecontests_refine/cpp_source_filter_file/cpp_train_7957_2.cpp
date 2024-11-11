#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000001;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main() {
  string s;
  int k, w[26];
  cin >> s >> k;
  int m;
  for (int i = 0; i < (int)(26); i++) {
    cin >> w[i];
    m = max(m, w[i]);
  }
  long long ans = 0;
  for (int i = 0; i < (int)(s.size()); i++) ans += w[(int)s[i] - 'a'] * (i + 1);
  for (int i = 0; i < (int)(k); i++) ans += m * (s.size() + i + i);
  cout << (ans) << endl;
  return 0;
}
