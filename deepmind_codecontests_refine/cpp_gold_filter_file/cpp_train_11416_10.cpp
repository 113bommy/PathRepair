#include <bits/stdc++.h>
using namespace std;
const long long mod = (int)1e9 + 7;
const int Max = 5001;
int arr[Max], arrInv[Max], cntPaths[Max][Max], answer[Max + Max], cntNodes[Max],
    cntPaths2[Max][Max], up[Max + Max];
long long power(long long a, long long b, long long c = mod) {
  if (b <= 0) return 1;
  long long temp = power(a, b / 2, c) % c;
  if (b % 2 == 0) {
    return (temp * temp) % c;
  } else {
    return (((a * temp) % c) * temp) % c;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> arr[i];
    arrInv[i] = power(arr[i], mod - 2);
  }
  cntNodes[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cntNodes[i] = (1LL * cntNodes[i - 1] * arr[i - 1]) % mod;
  }
  for (int len = 1; len <= n - 1; ++len) {
    cntPaths[len][n] = 1;
    cntPaths2[0][n] = 1;
    cntPaths2[len][n] = 1;
    for (int depth = n - 1; depth >= 1; --depth) {
      cntPaths2[0][depth] = 1;
      cntPaths[len][depth] =
          (1LL * cntPaths[len][depth + 1] * arr[depth]) % mod;
      if (depth + len <= n - 1) {
        cntPaths[len][depth] =
            (1LL * cntPaths[len][depth] * arrInv[depth + len]) % mod;
      }
      cntPaths2[len][depth] =
          (1LL * cntPaths[len][depth] * arrInv[depth]) % mod;
      cntPaths2[len][depth] =
          (1LL * cntPaths2[len][depth] * (arr[depth] - 1)) % mod;
    }
  }
  for (int len = 1; len <= 2 * n - 2; ++len) answer[len] = up[len] = 0;
  for (int len = 1; len <= n - 1; ++len) {
    for (int depth = 1; depth + len <= n; ++depth) {
      answer[len] += (1LL * cntNodes[depth] * cntPaths[len][depth]) % mod;
      answer[len] %= mod;
    }
  }
  for (int depth = 2; depth <= n; ++depth) {
    for (int len = depth - 1 + n - 1; len >= 2; --len) {
      up[len] = up[len - 1];
    }
    up[1] = 0;
    for (int amountDown = 0; depth - 1 + amountDown <= n; ++amountDown) {
      int len = 1 + amountDown;
      up[len] += cntPaths2[amountDown][depth - 1];
      up[len] %= mod;
    }
    for (int len = 1; len <= depth - 1 + n - 1; ++len) {
      answer[len] += (1LL * cntNodes[depth] * up[len]) % mod;
      answer[len] %= mod;
    }
  }
  long long divideTwo = power(2, mod - 2);
  for (int len = 1; len <= 2 * n - 2; ++len) {
    cout << (1LL * answer[len] * divideTwo) % mod << ' ';
  }
  cout << '\n';
  return 0;
}
