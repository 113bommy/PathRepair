#include <bits/stdc++.h>
using namespace std;
const int N = 6;
string s[N], t = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<pair<char, int> > ans;
void add(int x, int y, char a, char b, char c) {
  if (a == 'D') swap(s[x][y], s[x + 1][y]);
  if (a == 'U') swap(s[x][y], s[x - 1][y]);
  if (a == 'L') swap(s[x][y], s[x][y + 1]);
  if (a == 'R') swap(s[x][y], s[x][y - 1]);
  if (a == 'U' || a == 'D') swap(x, y);
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(b, x));
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(a, x));
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(b, x));
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(a, x));
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(b, x));
  ans.push_back(pair<char, int>(c, y));
  ans.push_back(pair<char, int>(a, x));
  ans.push_back(pair<char, int>(c, y));
}
void move(int x, int y, int _x, int _y) {
  while (x < _x) add(x++, y, 'D', 'U', 'L');
  while (y < _y) add(x, y++, 'R', 'L', 'U');
  while (x > _x) add(x--, y, 'U', 'D', 'L');
  while (y > _y) add(x, y--, 'L', 'R', 'U');
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  for (int i = 0; i < N; i++) cin >> s[i];
  for (int k = 0; k < N * N; k++) {
    int x = -1, y = -1;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (s[i][j] == t[k]) {
          x = i;
          y = j;
        }
    move(x, y, k / N, k % N);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i.first << i.second + 1 << "\n";
  return 0;
}
