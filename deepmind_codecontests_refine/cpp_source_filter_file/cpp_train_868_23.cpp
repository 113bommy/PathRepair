#include <bits/stdc++.h>
using namespace std;
inline void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
int DM[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getDM(int m) {
  m;
  int res = 0;
  for (int i = 0; i < m; i++) res += DM[i];
  return res;
}
char c[int(1e5 + 5)];
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  multiset<int> s;
  int g, M, d, hh, mm, ss;
  int x;
  while (0 < scanf("%d-%d-%d %d:%d:%d:%[^\n]", &g, &M, &d, &hh, &mm, &ss, c)) {
    int time = ss + 60 * (mm + 60 * (hh + 24 * (d + getDM(M))));
    s.insert(time);
    while (*s.begin() <= time - n) s.erase(s.begin());
    if (s.size() == m) {
      printf("%d-%02d-%02d %02d:%02d:%02d\n", g, M, d, hh, mm, ss);
      return;
    }
  }
  cout << -1;
}
