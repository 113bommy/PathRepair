#include <bits/stdc++.h>
using namespace std;
int n, m, T, a[100010], b[100010], tree[400][410];
struct kkk {
  int l;
  vector<int> ve;
} kk[100010];
int lowbit(int x) { return x & (-x); }
void add(int row, int x, int k) {
  int i = x;
  while (i <= m) {
    tree[row][i] += k;
    i += lowbit(i);
  }
  return;
}
int getsum(int row, int x) {
  int i = x;
  int ans = 0;
  while (i >= 1) {
    ans += tree[row][i];
    i -= lowbit(i);
  }
  return ans;
}
map<int, int> ma;
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    ma.clear();
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
      kk[i].l = 0;
      kk[i].ve.clear();
    }
    for (int i = 1; i <= n * m; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(a + 1, a + n * m + 1);
    a[n * m + 1] = -1;
    int j = 1;
    ma[a[1]] = 1;
    for (int i = 1; i <= n * m; i++) {
      if (a[i] != a[i + 1]) {
        kk[j].l++;
        kk[j].ve.push_back(i);
        j++;
        ma[a[i + 1]] = j;
      } else if (i % m == 0) {
        kk[j].l++;
        kk[j].ve.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n * m; i++) {
      int x = ma[b[i]];
      for (int j = 0; j < kk[x].l; j++) {
        if (a[kk[x].ve[j]] == b[i] && kk[x].ve[j] > 0) {
          int p = kk[x].ve[j];
          ans += getsum((p - 1) / m + 1, (p - 1) % m);
          add((p - 1) / m + 1, (p - 1) % m + 1, 1);
          kk[x].ve[j]--;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
