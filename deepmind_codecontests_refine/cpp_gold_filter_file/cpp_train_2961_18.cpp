#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
const int BLK = 1000;
const int NBLK = maxn / BLK;
int n, m;
int a[maxn], op[maxn], q[maxn][2], c0[NBLK][maxn * 2], c1[NBLK][maxn];
void add(int i, int x) {
  c0[i][x]++;
  c1[i][c0[i][x]]++;
}
void del(int i, int x) {
  c1[i][c0[i][x]]--;
  c0[i][x]--;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int(i) = (0); (i) <= ((n)-1); (i)++) cin >> a[i];
  vector<int> candidates(a, a + n);
  cin >> m;
  for (int(i) = (0); (i) <= ((m)-1); (i)++) {
    cin >> op[i] >> q[i][0] >> q[i][1];
    if (op[i] == 1) candidates.emplace_back(q[i][0]);
  }
  sort((candidates).begin(), (candidates).end());
  (candidates)
      .erase(unique((candidates).begin(), (candidates).end()),
             (candidates).end());
  for (int(i) = (0); (i) <= ((n)-1); (i)++)
    a[i] = lower_bound((candidates).begin(), (candidates).end(), a[i]) -
           candidates.begin();
  for (int(i) = (0); (i) <= ((m)-1); (i)++)
    if (op[i] == 1)
      q[i][0] = lower_bound((candidates).begin(), (candidates).end(), q[i][0]) -
                candidates.begin();
  for (int i = 0; i * BLK < n; i++)
    for (int(j) = (0); (j) <= ((i * BLK) - 1); (j)++) add(i, a[j]);
  for (int(i) = (0); (i) <= ((m)-1); (i)++) {
    if (op[i] == 1) {
      int x = q[i][0], y = q[i][1] - 1;
      for (int j = y / BLK + 1; j * BLK < n; j++) {
        del(j, a[y]);
        add(j, x);
      }
      a[y] = x;
      continue;
    }
    int x = q[i][0], y = q[i][1] - 1;
    if (x == 1) {
      cout << candidates[a[y]] << '\n';
      continue;
    }
    int b = y / BLK;
    for (int(j) = (b * BLK); (j) <= (y); (j)++) add(b, a[j]);
    int c = c0[b][a[y]];
    if (x % 2 == 0)
      cout << c << '\n';
    else
      cout << c1[b][c] << '\n';
    for (int(j) = (b * BLK); (j) <= (y); (j)++) del(b, a[j]);
  }
}
