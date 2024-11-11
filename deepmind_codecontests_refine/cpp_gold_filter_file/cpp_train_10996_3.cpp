#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 1e6 + 5;
long long tmp[maxn];
long long n;
void init() {
  tmp[1] = 9;
  for (int i = 2; i <= 11; i++) tmp[i] = tmp[i - 1] * 10 + 9;
}
long long ans;
void dfs(long long val, long long index) {
  long long mid = val / 2;
  ans += min(min(val - 1LL, n) - (mid + 1LL) + 1LL, mid);
  for (int i = 1; i <= 9; i++) {
    long long tmp = i * index + val;
    if (tmp <= (n + n - 1)) {
      dfs(tmp, index * 10);
    }
  }
}
int main() {
  init();
  cin >> n;
  long long sum = n + n - 1;
  int nine;
  for (int i = 1;; i++) {
    if (tmp[i] > sum) {
      nine = i - 1;
      break;
    }
  }
  if (nine == 0) {
    printf("%d\n", n * (n - 1) / 2);
    return 0;
  }
  long long val = tmp[nine];
  long long index = 1;
  for (int i = 1; i <= nine; i++) index = 10 * index;
  dfs(val, index);
  cout << ans << endl;
  return 0;
}
