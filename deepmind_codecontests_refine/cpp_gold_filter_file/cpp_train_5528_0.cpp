#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 2;
int n, utile[NMAX];
string s, sRev;
int travail(string chaine) {
  bool d = true;
  int id = 0, maximum = -1, debut, fin, streak;
  while (n > id) {
    streak = 1;
    id++;
    while (n > id && chaine[id] != chaine[id - 1]) {
      streak++;
      id++;
    }
    if (d) {
      d = false;
      debut = streak;
    }
    maximum = max(maximum, streak);
    if (id >= n) {
      fin = streak;
    }
  }
  if (s[0] != s[n - 1] && maximum != n) {
    maximum = max(debut + fin, maximum);
  }
  return maximum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    sRev += s[n - 1 - i];
  }
  cout << max(travail(s), travail(sRev)) << '\n';
}
