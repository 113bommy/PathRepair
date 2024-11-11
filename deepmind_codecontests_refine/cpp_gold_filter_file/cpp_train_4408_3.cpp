#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
vector<int> v1, v2[15], v3[115];
int cnt1[1115][15], cnt2[1115][15], N, T, val, a[10][10];
int get_size(int val) {
  int ret = 0;
  while (val > 0) {
    ret++;
    val /= 10;
  }
  return ret;
}
bool is_prime(int val) {
  for (int i = 2; i * i <= val; i++)
    if (val % i == 0) return false;
  return true;
}
void pre_solve() {
  for (int i = 2; i < MAX_N; i++)
    if (is_prime(i)) {
      v1.push_back(i);
      v2[i / 10000].push_back(i);
      v3[i / 1000].push_back(i);
      cnt1[i / 100][i % 10]++;
      cnt2[i / 100][(i % 100) / 10]++;
    }
}
void first_clear() {
  N = 0;
  val = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) a[i][j] = 0;
}
void solve() {
  scanf("%d", &val);
  N = get_size(val);
  int ans = 0;
  if (N <= 2) {
    int lw = val % 10;
    for (int i = 0; i < 10; i++) {
      int x = lw * 10 + i;
      if (x == 0 || x == 1) continue;
      if (is_prime(x)) ans++;
    }
    printf("%d\n", ans);
    return;
  }
  int cpy = val, tt = N - 1;
  while (tt >= 0) {
    a[0][tt] = a[tt][0] = cpy % 10;
    cpy /= 10;
    tt--;
  }
  if (N == 3) {
    for (int i = 0; i < 10; i++) ans += cnt1[a[1][0]][i] * cnt2[a[2][0]][i];
    printf("%d\n", ans);
    return;
  }
  if (N == 4) {
    for (int i = 0; i < v3[a[1][0]].size(); i++) {
      int now = v3[a[1][0]][i];
      int cpy2 = now, tt2 = N - 1;
      while (tt2 >= 1) {
        a[1][tt2] = a[tt2][1] = cpy2 % 10;
        cpy2 /= 10;
        tt2--;
      }
      for (int j = 0; j < 10; j++)
        ans +=
            cnt1[a[2][0] * 10 + a[2][1]][j] * cnt2[a[3][0] * 10 + a[3][1]][j];
      a[1][1] = a[1][2] = a[1][3] = a[1][4] = 0;
      a[1][1] = a[2][1] = a[3][1] = a[4][1] = 0;
    }
    printf("%d\n", ans);
    return;
  }
  for (int i = 0; i < v2[a[1][0]].size(); i++) {
    int now = v2[a[1][0]][i], cpy2 = v2[a[1][0]][i], tt2 = N - 1;
    while (tt2 >= 1) {
      a[1][tt2] = a[tt2][1] = cpy2 % 10;
      cpy2 /= 10;
      tt2--;
    }
    for (int j = 0; j < v3[a[2][0] * 10 + a[2][1]].size(); j++) {
      int now = v3[a[2][0] * 10 + a[2][1]][j];
      int cpy3 = now, tt3 = N - 1;
      while (tt3 >= 2) {
        a[2][tt3] = a[tt3][2] = cpy3 % 10;
        cpy3 /= 10;
        tt3--;
      }
      for (int k = 0; k < 10; k++)
        ans += cnt1[a[3][0] * 100 + a[3][1] * 10 + a[3][2]][k] *
               cnt2[a[4][0] * 100 + a[4][1] * 10 + a[4][2]][k];
      a[2][2] = a[3][2] = a[4][2] = 0;
      a[2][2] = a[2][3] = a[2][4] = 0;
    }
    a[1][1] = a[1][2] = a[1][3] = a[1][4] = 0;
    a[1][1] = a[2][1] = a[3][1] = a[4][1] = 0;
  }
  printf("%d\n", ans);
}
int main() {
  pre_solve();
  scanf("%d", &T);
  while (T--) {
    first_clear();
    solve();
  }
  return 0;
}
