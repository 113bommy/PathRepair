#include <bits/stdc++.h>
using namespace std;
long long t = 1;
void solve() {
  long long cnt = 0, h = 0, hh, n, row = 1, col = 1;
  string s;
  cin >> n >> s;
  vector<vector<char> > v(500, vector<char>(500, '#'));
  for (long long i = 0; i < int((s).size()); i += 1) {
    if (s[i] == '[')
      cnt++;
    else
      cnt--;
    h = max(cnt, h);
  }
  hh = h;
  h = 2 * h;
  for (long long i = 0; i < int((s).size()) - 1; i += 1) {
    if (s[i] == '[') {
      v[row][col] = '+';
      v[row][col + 1] = '-';
      for (long long j = row + 1; j < row + h; j += 1) v[j][col] = '|';
      v[row + h][col] = '+';
      v[row + h][col + 1] = '-';
      if (s[i + 1] == '[') {
        h -= 2;
        row += 1;
        col += 1;
      } else {
        col += 4;
      }
    } else {
      v[row][col] = '+';
      v[row][col - 1] = '-';
      for (long long j = row + 1; j < row + h; j += 1) {
        v[j][col] = '|';
      }
      v[row + h][col] = '+';
      v[row + h][col - 1] = '-';
      if (s[i + 1] == ']') {
        row -= 1;
        col += 1;
        h += 2;
      } else {
        col += 1;
      }
    }
  }
  v[row][col] = '+';
  v[row][col - 1] = '-';
  for (long long i = row + 1; i < row + h; i += 1) v[i][col] = '|';
  v[row + h][col] = '+';
  v[row + h][col - 1] = '-';
  for (long long i = 1; i < 2 * hh + 2; i += 1) {
    for (long long j = 1; j < col + 1; j += 1) {
      if (v[i][j] != '#')
        cout << v[i][j];
      else
        cout << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) solve();
  return 0;
}
