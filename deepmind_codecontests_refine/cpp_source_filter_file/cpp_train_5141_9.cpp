#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int s[100005];
int mask[25];
struct Reg {
  int l, r;
} reg[23][100];
bool test(int p) {
  if (p == n) return true;
  set<int> q[2];
  set<int>::iterator pp;
  int now = 1, nxt = 1;
  q[0].insert(mask[p] - 1);
  for (int i = p; i < n; i++) {
    nxt = now;
    now = now ^ 1;
    for (pp = q[now].begin(); pp != q[now].end(); pp++) {
      int mask_n = *pp;
      bool ok = false;
      for (int j = 1; j <= reg[i][0].l; j++) {
        if ((mask[reg[i][j].l] & mask_n) && (mask[reg[i][j].r] & mask_n)) {
          ok = true;
          break;
        }
      }
      if (ok) {
        for (int j = 0; j < i; j++) {
          if (mask_n & mask[j]) {
            q[nxt].insert((mask_n - mask[j]) | mask[i]);
          }
        }
      }
    }
    q[now].clear();
  }
  return (!q[now ^ 1].empty());
}
int main() {
  mask[0] = 1;
  for (int i = 1; i < 25; i++) mask[i] = (mask[i - 1] << 1);
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> s[i];
  bool ok;
  for (int i = 1; i < n; i++) {
    ok = false;
    for (int j = 0; j < i; j++) {
      for (int k = 0; k <= j; k++) {
        if (s[j] + s[k] == s[i]) {
          ok = true;
          reg[i][0].l++;
          reg[i][reg[i][0].l].l = j;
          reg[i][reg[i][0].l].r = k;
        }
      }
    }
    if (ok == false) break;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  int l = 1, r = n;
  int ret = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (test(mid)) {
      r = mid - 1;
      ret = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ret << endl;
  return 0;
}
