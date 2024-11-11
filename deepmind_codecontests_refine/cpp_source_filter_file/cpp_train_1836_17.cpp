#include <bits/stdc++.h>
using namespace std;
int a[3];
string result = "strange";
map<string, int> num;
int main() {
  int ii;
  int cur[3] = {0, 1, 2}, t1, t2;
  string str;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  num["C"] = 0;
  num["C#"] = 1;
  num["D"] = 2;
  num["D#"] = 3;
  num["E"] = 4;
  num["F"] = 5;
  num["F#"] = 6;
  num["G"] = 7;
  num["G3"] = 8;
  num["A"] = 9;
  num["B"] = 10;
  num["H"] = 11;
  for (ii = 0; ii < 3; ii++) {
    cin >> str;
    a[ii] = num[str];
  }
  for (ii = 0; (ii < 6) && (result == "strange"); ii++) {
    t1 = (a[cur[1]] - a[cur[0]] + 11) % 12 + 1;
    t2 = (a[cur[2]] - a[cur[1]] + 11) % 12 + 1;
    if ((t1 == 4) && (t2 == 3))
      result = "major";
    else if ((t1 == 3) && (t2 == 4))
      result = "minor";
    next_permutation(cur, (cur + 3));
  }
  cout << result << "\n";
  return 0;
}
