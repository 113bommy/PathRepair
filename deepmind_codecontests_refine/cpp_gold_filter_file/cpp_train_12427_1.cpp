#include <bits/stdc++.h>
using namespace std;
long long len[55], pCnt[55][105];
int getPower(long long x) {
  int ans = 0;
  while (x > 1) {
    if (x % 2 != 0) {
      return -1;
    }
    ans++;
    x /= 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long answer = 0;
  long long n, t;
  cin >> n >> t;
  n++;
  t = getPower(t);
  if (t == -1) {
    cout << "0" << '\n';
    return 0;
  }
  len[0] = 1;
  for (int i = 1; i < 50; i++) {
    len[i] = len[i - 1] + len[i - 1];
  }
  pCnt[0][0] = 1;
  for (int i = 1; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      pCnt[i][j] += pCnt[i - 1][j];
    }
    for (int j = 1; j < 50; j++) {
      pCnt[i][j] += pCnt[i - 1][j - 1];
    }
  }
  int offset = 0;
  long long half = (1LL << 52);
  while (n != 0) {
    for (int i = 0; i < 50; i++) {
      if (len[i] <= n) {
        n -= len[i];
        if (t - offset >= 0) answer += pCnt[i][t - offset];
        half -= len[i];
        if (half == 0) offset++;
      } else {
        half = len[i - 1] / 2;
        break;
      }
    }
    break;
  }
  while (n != 0) {
    for (int i = 49; i >= 0; i--) {
      if (len[i] <= n) {
        n -= len[i];
        answer += pCnt[i][t - offset];
        break;
      }
    }
    offset++;
  }
  if (t == 0) answer--;
  cout << answer << '\n';
}
