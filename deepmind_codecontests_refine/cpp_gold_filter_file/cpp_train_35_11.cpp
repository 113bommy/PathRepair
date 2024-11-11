#include <bits/stdc++.h>
using namespace std;
string s;
int num[2][13][105];
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve(string d) {
  if (d[0] == '-' || d[1] == '-' || d[2] != '-' || d[3] == '-' || d[4] == '-' ||
      d[5] != '-' || d[6] == '-' || d[7] == '-' || d[8] == '-' || d[9] == '-')
    return;
  int p = 0, y = 0, m = 0;
  string t;
  for (int i = 0; i < 2; i++) p = p * 10 + d[i] - '0';
  for (int i = 3; i < 5; i++) m = m * 10 + d[i] - '0';
  for (int i = 6; i < 10; i++) y = y * 10 + d[i] - '0';
  if (y < 2013 || y > 2015) return;
  if (m < 1 || m > 12) return;
  if (p < 1 || p > month[m]) return;
  num[y - 2013][m][p]++;
}
int y, m, d, mx;
void print() {
  if (d < 10) cout << '0';
  cout << d << '-';
  if (m < 10) cout << '0';
  cout << m;
  cout << '-' << y;
}
int main() {
  cin >> s;
  for (int i = 0; i + 9 < s.size(); i++) solve(s.substr(i, 10));
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= 12; j++)
      for (int k = 1; k <= month[j]; k++) {
        if (num[i][j][k] > mx) {
          y = i + 2013, m = j, d = k;
          mx = num[i][j][k];
        }
      }
  print();
  return 0;
}
