#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, n, can, res, aux[30];
  bool let[30];
  string s1, s2;
  cin >> n;
  memset(let, 0, sizeof let);
  memset(aux, 0, sizeof aux);
  can = 26;
  res = 0;
  for (i = 1; i <= n; i++) {
    cin >> s1 >> s2;
    if (can > 1) {
      for (j = 0; j < s2.length(); j++) {
        aux[s2[j] - 'a'] = n;
      }
      if (s1 == "!") {
        for (j = 0; j < 26; j++) {
          if (aux[j] != n && !let[j]) {
            let[j] = 1;
            can--;
          }
        }
      } else {
        for (j = 0; j < 26; j++) {
          if (aux[j] == n && !let[j]) {
            let[j] = 1;
            can--;
          }
        }
      }
    } else {
      if (s1 == "?" || s1 == "!") res++;
    }
  }
  res--;
  if (res < 0) res = 0;
  cout << res << endl;
}
