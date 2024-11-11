#include <bits/stdc++.h>
using namespace std;
int main() {
  int l = -2000000000, h = 2000000000, n, i, k;
  string s;
  char t;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s >> k >> t;
    if ((s == ">=" && t == 'Y') || (s == "<" && t == 'N'))
      l = max(k, l);
    else if ((s == "<=" && t == 'Y') || (s == ">" && t == 'N'))
      h = min(k, h);
    else if ((s == ">" && t == 'Y') || (s == "<=" && t == 'N'))
      l = max(k + 1, l);
    else
      h = min(k, h);
  }
  if (l >= h)
    cout << "Impossible\n";
  else
    cout << l << endl;
}
