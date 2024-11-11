#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
const int MAXM = 26 + 3;
char str[MAXN];
int treecnt;
string out[MAXN];
int vis2[MAXN], vis3[MAXN];
int len;
bool check(int st, int l) {
  int ok = 0;
  if (st + 2 * l > len) {
    if (st + 2 * l != len + 1) return false;
    return true;
  }
  for (int i = st; i < st + l; i++) {
    if (str[i] != str[i + l]) return true;
  }
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%s", str);
  len = strlen(str);
  int cnt = 0;
  memset(vis2, 0, sizeof vis2);
  memset(vis3, 0, sizeof vis3);
  vis2[len] = 1;
  vis3[len] = 1;
  for (int i = len - 1; i >= 0; i--) {
    if (i <= 4) break;
    int ok = 0;
    int t1, t2;
    t1 = t2 = 0;
    if ((vis3[i + 2] || (vis2[i + 2] && check(i, 2)))) t1 = 1;
    if ((vis2[i + 3] || (vis3[i + 3] && check(i, 3)))) t2 = 1;
    if (t1) {
      out[cnt] = "";
      for (int j = i; j < i + 2; j++) out[cnt] += str[j];
      cnt++;
      vis2[i] = 1;
    }
    if (t2) {
      out[cnt] = "";
      for (int j = i; j < i + 3; j++) out[cnt] += str[j];
      cnt++;
      vis3[i] = 1;
    }
  }
  int ans = 0;
  sort(out, out + cnt);
  for (int i = 1; i < cnt; i++)
    if (out[i] != out[i - 1]) ans++;
  cout << ans + (cnt > 0) << endl;
  for (int i = 0; i < cnt; i++) {
    if (i == 0 || out[i] != out[i - 1]) cout << out[i] << endl;
  }
  return 0;
}
