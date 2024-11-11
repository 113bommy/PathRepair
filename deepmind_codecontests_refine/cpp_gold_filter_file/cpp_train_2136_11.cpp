#include <bits/stdc++.h>
using namespace std;
int n;
char s[2][1111111];
int p[2], f;
set<pair<int, int> > st;
char rev(char ch) {
  if (ch == 'W') return 'E';
  if (ch == 'E') return 'W';
  if (ch == 'N') return 'S';
  if (ch == 'S') return 'N';
  return ' ';
}
void process(int x, int _x) {
  for (; p[x] < n; p[x]++) {
    char op = s[x][p[x]], _op = s[_x][p[_x]];
    char forbid1 = op, forbid2 = p[x] ? rev(s[x][p[x] - 1]) : ' ';
    while (p[_x] < n && _op != forbid1 && _op != forbid2) {
      p[_x]++;
      _op = s[_x][p[_x]];
    }
    if (p[_x] < n && op == _op) p[_x]++;
    if (p[_x] && op == rev(s[_x][p[_x] - 1])) p[_x]--;
  }
}
int main() {
  scanf("%d%s%s", &n, s[0], s[1]);
  n--;
  p[0] = p[1] = f = 0;
  st.clear();
  do {
    st.insert(make_pair(p[0], p[1]));
    process(f, 1 - f);
    f = 1 - f;
  } while (st.find(make_pair(p[0], p[1])) == st.end());
  printf("%s\n", (p[0] == n && p[1] == n) ? "YES" : "NO");
  return 0;
}
