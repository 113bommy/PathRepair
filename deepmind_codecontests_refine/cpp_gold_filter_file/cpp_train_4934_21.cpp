#include <bits/stdc++.h>
using namespace std;
int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> parse(string s) {
  int i, dd, mm, yy;
  for ((i) = 0; (i) < (int)(s.length()); i++)
    if (s[i] == '.') s[i] = ' ';
  istringstream ss(s);
  ss >> dd >> mm >> yy;
  vector<int> ans;
  ans.push_back(dd);
  ans.push_back(mm);
  ans.push_back(yy);
  return ans;
}
bool legal(vector<int> v) {
  int d = v[0], m = v[1], y = v[2];
  if (y % 4 == 0 && m == 2 && d == 29) return true;
  if (m <= 12 && d <= a[m - 1]) return true;
  return false;
}
bool func(vector<int> contest, vector<int> birth) {
  sort(birth.begin(), birth.end());
  do {
    if (!legal(birth)) continue;
    if (birth[2] < contest[2] - 18) return true;
    if (birth[2] == contest[2] - 18) {
      if (birth[1] < contest[1]) return true;
      if (birth[1] == contest[1] && birth[0] <= contest[0]) return true;
    }
  } while (next_permutation(birth.begin(), birth.end()));
  return false;
}
int main(void) {
  string contest, birth;
  cin >> contest >> birth;
  bool ans = func(parse(contest), parse(birth));
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
