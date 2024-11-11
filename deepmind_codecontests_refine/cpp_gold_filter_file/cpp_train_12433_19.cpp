#include <bits/stdc++.h>
using namespace std;
int i, j, cnt[3], wins[2];
char a[4][4];
vector<char> vec;
map<char, int> mp = {{'X', 0}, {'0', 1}, {'.', 2}};
int main() {
  cin >> a[0] >> a[1] >> a[2];
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) cnt[mp[a[i][j]]]++;
  for (i = 0; i < 3; ++i) {
    if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][1] != '.')
      vec.push_back(a[i][1]), wins[0]++;
    if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[1][i] != '.')
      vec.push_back(a[1][i]), wins[1]++;
  }
  if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != '.')
    vec.push_back(a[1][1]);
  if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] != '.')
    vec.push_back(a[1][1]);
  if (cnt[0] != cnt[1] && cnt[0] != cnt[1] + 1 || wins[0] > 1 || wins[1] > 1)
    return cout << "illegal", 0;
  for (i = 1; i < vec.size(); ++i)
    if (vec[i] != vec[i - 1]) return cout << "illegal", 0;
  if (vec.size()) {
    if (vec[0] == 'X')
      cout << (cnt[0] == cnt[1] + 1 ? "the first player won" : "illegal");
    else
      cout << (cnt[0] == cnt[1] ? "the second player won" : "illegal");
    return 0;
  }
  if (cnt[0] + cnt[1] == 9)
    cout << "draw";
  else
    cout << (cnt[0] == cnt[1] ? "first" : "second");
  return 0;
}
