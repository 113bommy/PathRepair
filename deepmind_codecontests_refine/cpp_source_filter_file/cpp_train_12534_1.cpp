#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 9;
int N;
long long a[MAXN];
long long b[MAXN];
int cd[MAXN];
int cnt_divs(long long n) {
  int ret = 0;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret++;
      n /= i;
    }
  }
  return ret + (n > 1);
}
bool forest;
int cost() {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int d = cd[i];
    if (d > 1 || a[i] != b[i]) ans += d;
  }
  return ans + N + forest;
}
int solve(int at) {
  if (at == N)
    return cost();
  else if (at == 0) {
    int ret = INF;
    forest = true;
    ret = min(ret, solve(at + 1));
    forest = false;
    ret = min(ret, solve(at + 1));
    return ret;
  } else {
    int ret = INF;
    if (forest) ret = min(ret, solve(at + 1));
    for (int i = 0; i < at; i++) {
      if (a[i] % a[at] == 0) {
        a[i] /= a[at];
        cd[i] -= cd[at];
        ret = min(ret, solve(at + 1));
        cd[i] += cd[at];
        a[i] *= a[at];
      }
    }
    return ret;
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N, greater<int>());
  for (int i = 0; i < N; i++) cd[i] = cnt_divs(a[i]);
  memcpy(b, a, sizeof(b));
  cout << solve(0) << endl;
  return 0;
}
