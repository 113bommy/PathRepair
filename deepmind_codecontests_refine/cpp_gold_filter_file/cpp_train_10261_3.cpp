#include <bits/stdc++.h>
using namespace std;
int QL[1000001];
int gcd(int first, int second) {
  return second == 0 ? first : gcd(second, first % second);
}
int n, m;
int Gc[51][51];
vector<pair<int, int> > H[1000001];
char c;
inline void read(int &a) {
  a = 0;
  do c = getchar();
  while (c < '0' || c > '9');
  while (c <= '9' && c >= '0') a = (a << 3) + (a << 1) + c - '0', c = getchar();
}
inline int Max(int &a, int b) { return a > b ? a : a = b; }
int cnt[51], res[51];
bool insert(pair<int, int> P) {
  bool f = 1;
  for (int i = 1; i <= 40; i++)
    if (f && cnt[i] && ((P.second - res[i]) % Gc[QL[P.first]][i])) return 0;
  return res[QL[P.first]] = P.second, cnt[QL[P.first]]++, f;
}
void erase(pair<int, int> P) { cnt[QL[P.first]]--; }
inline void Calc(int first) {
  int ans = 0, i = 0, j = 0, k, t = 0;
  memset(cnt, 0, sizeof(cnt));
  while (j < H[first].size()) {
    while (j < H[first].size() &&
           i - j == H[first][i].first - H[first][j].first &&
           insert(H[first][j]))
      j++;
    erase(H[first][i]);
    Max(ans, j - i);
    i++;
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1, i = 1, re;
  for (int i = 0; i <= 40; i++)
    for (int j = 0; j <= 40; j++) Gc[i][j] = gcd(i, j);
  Gc[0][0] = 1;
  read(n), read(m);
  for (int i = 0; i < n; i++) {
    int k, t;
    read(QL[i]);
    for (int j = 0; j < QL[i]; j++) read(t), H[t].push_back(make_pair(i, j));
  }
  for (int i = 1; i <= m; i++) Calc(i);
  return 0;
}
