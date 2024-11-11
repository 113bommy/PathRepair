#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1010;
bitset<maxn << 1> a[maxn << 1];
int t[maxn << 1];
int cnt;
int getid(char c) {
  if (c == 'W') return 0;
  if (c == 'R') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  assert(0);
}
int x[maxn << 1];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) t[i * 2 - 1] = 1, t[i * 2] = 2;
  for (int i = 1; i <= m; i++) {
    string s, em;
    int len;
    cin >> s >> len;
    vector<int> pos(len);
    for (int i = 0; i < len; i++) {
      cin >> pos[i];
    }
    if (s == "mix") {
      cin >> em;
      ++cnt;
      for (int i = 0; i < len; i++) {
        a[cnt][pos[i] * 2 - 1] = t[pos[i] * 2 - 1] & 1;
        a[cnt][pos[i] * 2] = t[pos[i] * 2 - 1] >> 1 & 1;
      }
      a[cnt][n * 2 + 1] = getid(em[0]) & 1;
      ++cnt;
      for (int i = 0; i < len; i++) {
        a[cnt][pos[i] * 2 - 1] = t[pos[i] * 2] & 1;
        a[cnt][pos[i] * 2] = t[pos[i] * 2] >> 1 & 1;
      }
      a[cnt][n * 2 + 1] = getid(em[0]) >> 1 & 1;
    }
    if (s == "RY") {
      for (int i = 0; i < len; i++) swap(t[pos[i] * 2 - 1], t[pos[i] * 2]);
    }
    if (s == "YB") {
      for (int i = 0; i < len; i++) t[pos[i] * 2] ^= t[pos[i] * 2 - 1];
    }
    if (s == "RB") {
      for (int i = 0; i < len; i++) t[pos[i] * 2 - 1] ^= t[pos[i] * 2];
    }
  }
  int cur = 1;
  for (int i = 1; i <= n * 2 && cur <= cnt; i++) {
    int j = cur;
    while (j <= cnt && !a[j][i]) j++;
    if (j > cnt) continue;
    if (cur != j) swap(a[cur], a[j]);
    for (int j = 1; j <= cnt; j++) {
      if (cur != j && a[j][i]) {
        a[j] ^= a[cur];
      }
    }
    cur++;
  }
  cur--;
  for (int i = cur + 1; i <= cnt; i++)
    if (a[i][n * 2 + 1]) return puts("NO"), 0;
  for (int i = 1; i <= cur; i++) {
    int j = 1;
    while (!a[i][j]) j++;
    x[j] = a[i][n * 2 + 1];
    for (int k = j + 1; k <= 2 * n; ++k)
      if (a[i][k]) x[j] ^= x[k];
  }
  puts("YES");
  for (int i = 1; i <= n; i++) cout << ".RYB"[x[i * 2 - 1] + (x[i * 2] << 1)];
  return 0;
}
