/**
 *    author:  tourist
 *    created: 29.12.2019 23:02:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  vector<string> s(100, string(100, '.'));
  for (int i = 0; i < 50; i++) for (int j = 0; j < 100; j++) s[i][j] = '#';
  for (int i = 0; i < 50; i += 2) for (int j = 0; j < 100; j += 2) if (a > 1) { s[i][j] = '#'; --a; }
  for (int i = 0; i < 50; i += 2) for (int j = 0; j < 100; j += 2) if (b > 1) { s[h - 1 - i][j] = '#'; --b; }
  cout << 100 << " " << 100 << '\n';
  for (int i = 0; i < 100; i++) cout << s[i] << '\n';
  return 0;
}
