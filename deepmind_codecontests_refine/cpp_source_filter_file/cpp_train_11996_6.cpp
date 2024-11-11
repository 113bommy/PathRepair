#include <bits/stdc++.h>
using namespace std;
int N, M, t, ans[5010];
bool flag = false;
int main() {
  cin >> N >> M;
  int k;
  for (k = 1; k <= N; k++) {
    t += (k - 1) / 2;
    if (t <= M)
      ans[k] = k;
    else {
      flag = true;
      break;
    }
  }
  if (flag == false && t != M) return puts("-1") & 0;
  if (flag == false && t == M) {
    for (int i = 1; i <= N; i++) cout << i << ' ';
    return 0;
  }
  t -= (k - 1) / 2, k--;
  ans[k + 1] = 2 * k - (M - t) * 2 + 1;
  for (int i = k + 2; i <= N; i++) ans[i] = 10000000 + 1000 * i;
  for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
  return 0;
}
