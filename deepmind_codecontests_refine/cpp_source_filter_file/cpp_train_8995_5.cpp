#include <bits/stdc++.h>
using namespace std;
const int MAXB = 64, T = 6;
long long trans[T][T] = {{2, 1, 1, 0, 1, 2}, {1, 2, 0, 1, 1, 2},
                         {1, 1, 1, 0, 1, 2}, {1, 1, 0, 1, 1, 2},
                         {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1}};
long long v[T], tmp[T][T], ans[T][T], fin[T];
long long t, n;
inline void mul(long long des[][T], long long a[][T], long long b[][T]) {
  memset(des, 0, sizeof trans);
  for (int i = 0; i < T; i++)
    for (int k = 0; k < T; k++)
      for (int j = 0; j < T; j++) {
        des[i][j] += a[i][k] * b[k][j];
        des[i][j] %= n;
      }
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> v[0] >> v[1] >> v[2] >> v[3] >> t;
  while (v[2] < 0) v[2] += n;
  while (v[3] < 0) v[3] += n;
  v[0]--;
  v[1]--;
  v[4] = v[5] = 1;
  for (int i = 0; i < T; i++) ans[i][i] = 1;
  for (int i = 0; i < 63; i++) {
    if (t >> i & 1) {
      memcpy(tmp, ans, sizeof ans);
      mul(ans, tmp, trans);
    }
    memcpy(tmp, trans, sizeof trans);
    mul(trans, tmp, tmp);
  }
  for (int i = 0; i < T; i++)
    for (int j = 0; j < T; j++) {
      fin[i] += ans[i][j] * v[j];
      fin[i] %= n;
    }
  cout << fin[0] + 1 << " " << fin[1] + 1 << endl;
}
