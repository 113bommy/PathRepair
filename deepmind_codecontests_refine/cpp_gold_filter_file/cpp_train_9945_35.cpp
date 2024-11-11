#include <bits/stdc++.h>
using namespace std;
int next() {
  int x;
  cin >> x;
  return x;
}
long long lnext() {
  long long x;
  cin >> x;
  return x;
}
int main() {
  cout.precision(20);
  ios_base::sync_with_stdio(false);
  string s[2];
  string t[2];
  for (int i = 0; i < 2; i++) cin >> s[i];
  for (int i = 0; i < 2; i++) cin >> t[i];
  int x[4] = {0, 1, 1, 0};
  int y[4] = {0, 0, 1, 1};
  vector<char> ss, tt;
  for (int i = 0; i < 4; i++)
    if (s[x[i]][y[i]] != 'X') ss.push_back(s[x[i]][y[i]]);
  for (int i = 0; i < 4; i++)
    if (t[x[i]][y[i]] != 'X') tt.push_back(t[x[i]][y[i]]);
  for (int i = 0; i < 3; i++) ss.push_back(ss[i]);
  for (int i = 0; i < 3; i++) tt.push_back(tt[i]);
  int is = 0;
  int it = 0;
  while (ss[is] != 'A') is++;
  while (tt[it] != 'A') it++;
  if (ss[is + 1] == tt[it + 1])
    cout << "YES";
  else
    cout << "NO";
}
