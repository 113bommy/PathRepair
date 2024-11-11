#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main(int argc, char** argv) {
  map<string, int> f, g;
  string s[1000];
  int c[1000], n;
  int i, m = 0;
  string h;
  cin >> n;
  for (i = 0; i < n; ++i) cin >> s[i] >> c[i], f[s[i]] += c[i];
  for (i = 0; i < n; ++i) {
    if (m < f[s[i]]) m = f[s[i]];
  }
  i = 0;
  while (i < n) {
    if ((g[s[i]] += c[i]) == m && f[s[i]] == m) {
      h = s[i];
      break;
    }
    i++;
  }
  cout << h;
  return 0;
}
