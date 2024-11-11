#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int val[110][110];
int deal_c(int x) {
  int i, j;
  int res = 0;
  for (j = 0; j < M; j++) {
    int temp = 0;
    for (i = 0; i < N; i++) {
      temp += val[i][j] == val[i][x];
    }
    res += min(temp, N - temp);
  }
  return res;
}
int deal_r(int st) {
  int i, j;
  int res = 0;
  for (i = 0; i < N; i++) {
    int temp = 0;
    for (j = 0; j < M; j++) {
      if (st & (1 << j)) {
        temp += val[i][j] == 1;
      } else {
        temp += val[i][j] == 0;
      }
    }
    res += min(temp, M - temp);
  }
  return res;
}
int main() {
  int i, j;
  cin >> N >> M >> K;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      cin >> val[i][j];
    }
  }
  int ans = 100000;
  if (M > K) {
    for (i = 0; i < M; i++) {
      ans = min(ans, deal_c(i));
    }
  } else {
    int st = 1 << M;
    for (i = 0; i < st; i++) {
      ans = min(ans, deal_r(i));
    }
  }
  if (ans > K) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
