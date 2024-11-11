#include <bits/stdc++.h>
using namespace std;
int readInt;
int readChar;
inline int getInt() {
  readInt = 0;
  readChar = getchar();
  while (!isdigit(readChar)) readChar = getchar();
  while (isdigit(readChar))
    readInt = (readInt << 3) + (readInt << 1) + readChar - '0',
    readChar = getchar();
  return readInt;
}
int n;
int a[100010];
int maxLocal[20][100010];
long long result, dp[100010];
inline int maxInd(int indx1, int indx2) {
  return a[indx1] >= a[indx2] ? indx1 : indx2;
}
inline int query(int left, int right) {
  int bit = log2(right - left);
  return maxInd(maxLocal[bit][left], maxLocal[bit][right - (1 << bit)]);
}
int main() {
  int i, j, m, pow2value, pow2ind = 1;
  scanf("%d", &n);
  for (i = 1; i < n; i++) a[i] = getInt(), maxLocal[0][i] = i;
  maxLocal[0][n] = n;
  for (pow2value = 1; pow2value <= n; pow2value = (pow2value << 1), pow2ind++) {
    for (i = 1; i + pow2value <= n; i++) {
      maxLocal[pow2ind][i] = maxInd(maxLocal[pow2ind - 1][i],
                                    maxLocal[pow2ind - 1][i + pow2value]);
    }
  }
  for (i = n - 1; i > 0; i--) {
    m = query(i + 1, a[i] + 1);
    dp[i] = dp[m] - a[i] + m + n - i;
    result += dp[i];
  }
  cout << result << endl;
  return 0;
}
