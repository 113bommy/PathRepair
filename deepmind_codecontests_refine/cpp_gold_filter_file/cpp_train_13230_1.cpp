#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
inline int read() {
  int sum = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum * f;
}
int n, cnt[70], tmp[6], m, can[N], need[70];
string s, ans;
void del(int u, int v) {
  for (int i = 0; i < 64; i++) {
    if (can[u] & i) need[i]--;
    if (i & (1 << v)) cnt[i]--;
  }
}
void add(int u, int v) {
  for (int i = 0; i < 64; i++) {
    if (can[u] & i) need[i]++;
    if (i & (1 << v)) cnt[i]++;
  }
}
bool check() {
  for (int i = 0; i < 64; i++)
    if (cnt[i] > need[i]) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) tmp[s[i] - 'a']++;
  for (int i = 1; i < 64; i++) {
    for (int j = 0; j < 6; j++) {
      if (i & (1 << j)) {
        cnt[i] += tmp[j];
      }
    }
  }
  cin >> m;
  for (int i = 1; i <= n; i++) can[i] = 63;
  for (int i = 1; i <= m; i++) {
    int p, cant = 0;
    cin >> p >> s;
    for (int j = 0; j < s.size(); j++) cant |= (1 << (s[j] - 'a'));
    can[p] &= cant;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 64; j++) {
      if (can[i] & j) need[j]++;
    }
  }
  if (!check()) {
    cout << "Impossible" << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      if ((can[i] >> j) & 1) {
        del(i, j);
        if (check()) {
          ans += char(j + 'a');
          break;
        }
        add(i, j);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
