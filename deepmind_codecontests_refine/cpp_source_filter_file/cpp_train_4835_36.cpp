#include <bits/stdc++.h>
using namespace std;
int A[128][128];
int n, m;
int Try(int ind) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int tmp0 = 0, tmp1 = 0;
    for (int j = 0; j < m; ++j) {
      int c0 = (A[i][j]) ? 1 : 0;
      int c1 = (A[i][j]) ? 0 : 1;
      if ((A[i][j] && c0 == 0) || (A[i][j] == 0 && c0)) ++tmp0;
      if ((A[i][j] && c1 == 0) || (A[i][j] == 0 && c1)) ++tmp1;
    }
    ret += min(tmp0, tmp1);
  }
  return ret;
}
int Try2(int st) {
  int ret = 0;
  for (int j = 0; j < m; ++j) {
    int tmp0 = 0, tmp1 = 0;
    for (int i = 0; i < n; ++i) {
      int c0 = (st & (1 << i)) ? 1 : 0;
      int c1 = (st & (1 << i)) ? 0 : 1;
      if ((A[i][j] && c0 == 0) || (A[i][j] == 0 && c0)) ++tmp0;
      if ((A[i][j] && c1 == 0) || (A[i][j] == 0 && c1)) ++tmp1;
    }
    ret += min(tmp0, tmp1);
  }
  return ret;
}
int main() {
  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> A[i][j];
  int ret = n * m;
  if (n <= k) {
    for (int st = 0; st < (1 << n); ++st) {
      int tmp = Try2(st);
      if (tmp < ret) ret = tmp;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      int tmp = Try(i);
      if (tmp < ret) ret = tmp;
    }
  }
  if (ret <= k)
    cout << ret;
  else
    cout << -1;
  return 0;
}
