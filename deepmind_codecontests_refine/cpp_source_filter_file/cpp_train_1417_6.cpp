#include <bits/stdc++.h>
using namespace std;
int a[20], b[20], f[10], pos;
long long l, r, ans;
bool check(int pos, bool Ll, bool Lr) {
  if (!Ll && !Lr) return true;
  if (pos == -1) return true;
  int up = Lr ? b[pos] : 9;
  int down = Ll ? a[pos] : 0;
  if (up < down) return false;
  bool flag;
  for (int i = down; i <= up; i++)
    if (f[i]) {
      f[i]--;
      flag = check(pos - 1, Ll && i == a[pos], Lr && i == b[pos]);
      f[i]++;
      if (flag) return true;
    }
  return false;
}
void dfs(int k, int tot) {
  if (k == 9) {
    f[k] = tot;
    if (check(pos - 1, 1, 1)) ans++;
    return;
  }
  for (int i = 0; i <= tot; i++) {
    f[k] = i;
    dfs(k + 1, tot - i);
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin >> l >> r;
  pos = 0;
  while (l) {
    a[pos++] = l % 10;
    l /= 10;
  }
  pos = 0;
  while (r) {
    b[pos++] = r % 10;
    r /= 10;
  }
  dfs(0, pos);
  cout << 1 << endl;
}
