#include <bits/stdc++.h>
using namespace std;
long long n, m, x;
char y;
string s, s1 = "";
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  s1 += 'a';
  s1 += s + 'a';
  int cnt = 0, c = 0;
  bool b = false;
  for (int i = 0; i < n + 2; i++) {
    if (s1[i] == '.') {
      c++;
      b = true;
    } else {
      if (b == true) cnt += c - 1;
      c = 0;
      b = false;
    }
  }
  if (c != 0) cnt += c - 1;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (y != '.' && s1[x] == '.') {
      if (s1[x - 1] == '.' && s1[x + 1] == '.')
        cnt -= 2;
      else if (s1[x - 1] == '.' && s1[x + 1] != '.' ||
               s1[x - 1] != '.' && s1[x + 1] == '.')
        cnt -= 1;
    } else if (y == '.' && s1[x] != '.') {
      if (s1[x - 1] == '.' && s1[x + 1] == '.')
        cnt += 2;
      else if (s1[x - 1] == '.' && s1[x + 1] != '.' ||
               s1[x - 1] != '.' && s1[x + 1] == '.')
        cnt += 1;
    }
    cout << cnt << endl;
    s1[x] = y;
  }
  return 0;
}
