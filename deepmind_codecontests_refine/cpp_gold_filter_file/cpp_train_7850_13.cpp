#include <bits/stdc++.h>
using namespace std;
inline string tos(int a) {
  ostringstream second;
  second << a;
  string s = second.str();
  return s;
}
const int maxn = 1000 + 10;
bool o[maxn][maxn];
int n = 2, c = 3, l;
int p = 1, cur, t;
inline void add(int e) {
  ++t;
  if (t == 9)
    cur = 2;
  else {
    cur = c++;
    ++n;
  }
  for (int j = 0; j < e; j++) {
    o[c][p] = o[p][c] = 1;
    o[cur][c] = o[c][cur] = 1;
    ++n;
    ++c;
  }
  p = cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  string s = tos(k);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') continue;
    l = s.size() - 1 - i;
    p = 1;
    t = 0;
    for (int j = 0; j < l; j++) add(10);
    add(s[i] - '0');
    for (int j = 0; j < 8 - l; j++) add(1);
  }
  cout << n << "\n";
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (o[i][j])
        cout << "Y";
      else
        cout << "N";
    }
    cout << "\n";
  }
}
