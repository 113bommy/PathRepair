#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005;
int say[NMAX];
int guilty[NMAX];
int not_guilty[NMAX];
bool criminal[NMAX];
int main() {
  ios_base ::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  m = n - m;
  for (int i = 1; i <= n; ++i) cin >> say[i];
  int total_guilty = 0;
  for (int i = 1; i <= n; ++i)
    if (say[i] > 0)
      ++guilty[say[i]], ++total_guilty;
    else
      ++not_guilty[-say[i]];
  int criminals = 0;
  for (int i = 1; i <= n; ++i)
    if (total_guilty - guilty[i] + not_guilty[i] == m)
      criminal[i] = true, ++criminals;
  if (criminals == 1) {
    for (int i = 1; i <= n; ++i)
      if (say[i] > 0) {
        if (criminal[say[i]])
          cout << "Truth" << '\n';
        else
          cout << "Lie" << '\n';
      } else {
        if (!criminal[say[i]])
          cout << "Truth" << '\n';
        else
          cout << "Lie" << '\n';
      }
  } else {
    for (int i = 1; i <= n; ++i)
      if (say[i] > 0) {
        if (criminal[say[i]])
          cout << "Not defined" << '\n';
        else
          cout << "Lie" << '\n';
      } else {
        if (!criminal[-say[i]])
          cout << "Truth" << '\n';
        else
          cout << "Not defined" << '\n';
      }
  }
  return 0;
}
