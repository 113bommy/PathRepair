#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1000001;
const bool DEBUG = false;
int a[MAXA];
int dp[MAXA];
int mybin(int s, int e) {
  if (dp[e] - dp[s] == 0) return 0;
  if (DEBUG) cerr << "MYBIN: " << s << " " << e << endl;
  if (s + 1 == e) {
    if (a[e] > 0) {
      return e;
    }
    return 0;
  }
  int m = (s + e) / 2;
  if (dp[e] - dp[m] > 0) {
    return mybin(m, e);
  }
  return mybin(s, m);
}
int main() {
  int n, x, temp, maxx = 0;
  cin >> n;
  fill(a, a + MAXA, 0);
  fill(dp, dp + MAXA, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x] += 1;
  }
  dp[0] = a[0];
  for (int i = 1; i < MAXA; i++) {
    dp[i] = dp[i - 1] + int(a[i] > 0);
  }
  for (int i = 0; i < MAXA; i++) {
    if (a[i] > 0) {
      for (int j = i + i; j < MAXA; j += i) {
        temp = mybin(j - i, j - 1);
        if (temp != 0) {
          if (DEBUG) cerr << "FIND: " << temp << " for " << i << endl;
        }
        temp %= i;
        if (temp > maxx) maxx = temp;
      }
    }
  }
  cout << maxx;
  return 0;
}
