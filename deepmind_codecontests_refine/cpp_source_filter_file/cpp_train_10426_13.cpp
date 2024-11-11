#include <bits/stdc++.h>
using namespace std;
string p[3][2] = {{"lios", "liala"}, {"etr", "etra"}, {"initis", "inites"}}, s;
pair<int, int> kind(string q) {
  int l = q.length();
  if (l >= 4 && q.substr(l - 4, 4) == p[0][0]) return pair<int, int>(0, 0);
  if (l >= 5 && q.substr(l - 5, 5) == p[0][1]) return pair<int, int>(0, 1);
  if (l >= 3 && q.substr(l - 3, 3) == p[1][0]) return pair<int, int>(1, 0);
  if (l >= 4 && q.substr(l - 4, 4) == p[1][1]) return pair<int, int>(1, 1);
  if (l >= 6 && q.substr(l - 6, 6) == p[2][0]) return pair<int, int>(2, 0);
  if (l >= 6 && q.substr(l - 6, 6) == p[2][1]) return pair<int, int>(2, 1);
  return pair<int, int>(-1, -1);
}
int tran[2][3] = {{0, 1, -1}, {-1, -1, 1}};
int main() {
  int g = -1, st = -1, ok = true, tow = false;
  cin >> s;
  g = kind(s).second;
  if (g != -1) st = tran[0][kind(s).first];
  while (cin >> s && ok) {
    tow = true;
    pair<int, int> t = kind(s);
    if (t.second != g) ok = false;
    if (st == -1) break;
    st = tran[st][t.first];
  }
  if ((tow && ok && st != -1) || (!tow && g != -1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
