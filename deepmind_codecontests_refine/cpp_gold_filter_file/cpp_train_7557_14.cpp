#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
int good[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string aux, pattern, cad;
  cin >> aux >> pattern;
  for (int i = 0; i < aux.size(); i++) good[aux[i]] = 1;
  int q;
  cin >> q;
  while (q--) {
    cin >> cad;
    int i = 0, j = pattern.size() - 1, h = cad.size() - 1;
    while (i <= j && i <= h &&
           (cad[i] == pattern[i] || (pattern[i] == '?' && good[cad[i]])))
      i++;
    while (h >= i && j >= i &&
           (cad[h] == pattern[j] || (pattern[j] == '?' && good[cad[h]])))
      j--, h--;
    if (i <= j && (pattern[i] != '*' || pattern[j] != '*'))
      cout << "NO" << '\n';
    else if (i <= j) {
      int f = 1;
      while (i <= h) f = min(f, 1 - good[cad[i++]]);
      if (f)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else if (i - 1 == j && i - 1 == h)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
