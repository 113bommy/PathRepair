#include <bits/stdc++.h>
using namespace std;
string x[100] = {"C",  "C#", "D",  "D#", "E",  "F",  "F#", "G",
                 "G#", "A",  "B",  "H",  "C",  "C#", "D",  "D#",
                 "E",  "F",  "F#", "G",  "G#", "A",  "B",  "H"};
string U[3] = {"strange", "major", "minor"};
int main() {
  string a[3];
  for (int i = 0; i < (int)3; ++i) cin >> a[i];
  int p[3] = {0, 1, 2};
  int ans = -1;
  do {
    int q[3] = {0, 0, 0};
    for (int i = 0; i < (int)3; ++i)
      while (x[q[i]] != a[p[i]]) q[i]++;
    if (x[q[0] + 4] == a[p[1]] && x[q[0] + 7] == a[p[2]]) ans = 0;
    if (x[q[0] + 3] == a[p[1]] && x[q[0] + 7] == a[p[2]]) ans = 1;
  } while (next_permutation(p, p + 3));
  cout << U[ans + 1];
  return 0;
}
