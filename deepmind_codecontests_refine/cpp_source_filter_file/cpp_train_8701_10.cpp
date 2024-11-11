#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 60;
short arr1[N], arr2[N], acc1[N], acc2[N], semi1[N], semi2[N], n, k;
short mem[N - 60 + 1][N - 60 + 1][51][2];
short f(int idx, int rem, int farag, int player) {
  if (rem < 0) return -1e3;
  if (idx >= n) return 0;
  short &ret = mem[idx][rem][farag][player];
  if (~ret) return ret;
  ret = f(idx + 1, rem, max(0, farag - 1), player);
  if (farag == 0) {
    ret = max(ret, short(f(idx + 1, rem - 1, k - 1, 0) + acc1[idx + k - 1] -
                         acc1[idx - 1]));
    ret = max(ret, short(f(idx + 1, rem - 1, k - 1, 1) + acc2[idx + k - 1] -
                         acc2[idx - 1]));
  } else {
    if (player == 0)
      ret = max(ret, short(f(idx + farag, rem - 1, k - farag, 1) +
                           semi2[idx + farag - 1] - semi2[idx - 1] +
                           acc2[idx + k - 1] - acc2[idx + farag - 1]));
    else
      ret = max(ret, short(f(idx + farag, rem - 1, k - farag, 0) +
                           semi1[idx + farag - 1] - semi1[idx - 1] +
                           acc1[idx + k - 1] - acc1[idx + farag - 1]));
  }
  return ret;
}
int main() {
  memset(mem, -1, sizeof mem);
  int p;
  cin >> n >> p >> k;
  int r, s;
  cin >> r;
  for (int i = 0, x; i < r; i++) cin >> x, arr1[x] = 1;
  cin >> s;
  for (int i = 0, x; i < s; i++) cin >> x, arr2[x] = 1;
  int ret = 0;
  for (int i = 1; i <= n + k + 2; i++) {
    ret += arr1[i];
    acc1[i] = ret;
  }
  ret = 0;
  for (int i = 1; i <= n + k + 2; i++) {
    ret += arr2[i];
    acc2[i] = ret;
  }
  ret = 0;
  for (int i = 1; i <= n + k + 2; i++) {
    if (arr1[i] && !arr2[i]) ret++;
    semi1[i] = ret;
  }
  ret = 0;
  for (int i = 1; i <= n + k + 2; i++) {
    if (!arr1[i] && arr2[i]) ret++;
    semi2[i] = ret;
  }
  cout << f(0, p, 0, 0) << '\n';
  return 0;
}
