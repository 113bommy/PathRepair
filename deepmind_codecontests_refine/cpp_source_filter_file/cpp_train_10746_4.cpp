#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9, MAXBIT = 24, M = 1 << MAXBIT;
int n, f[M], A[N], numbit[2], ans = 0;
void update(int x, int cnt) {
  for (; x; x -= x & -x) {
    f[x] += cnt;
  }
}
int getsum(int x) {
  int sum = 0;
  for (x; x < M; x += x & -x) {
    sum += f[x];
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int bit = 0; bit < 4; bit++) {
    int val = 1 << bit;
    long long exc = 0;
    numbit[0] = numbit[1] = 0;
    for (int i = 1; i <= n; i++) {
      numbit[A[i] / val % 2]++;
      update(A[i] % val, 1);
    }
    for (int i = 1; i <= n; i++) {
      update(A[i] % val, -1);
      exc += getsum(val - (A[i] % val));
      update(A[i] % val, 1);
    }
    for (int i = 1; i <= n; i++) {
      update(A[i] % val, -1);
    }
    exc /= 2;
    ans += (1ll * numbit[0] * numbit[1] + exc) % 2 * val;
  }
  cout << ans << '\n';
  return 0;
}
