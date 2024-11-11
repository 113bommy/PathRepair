#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
const int INF = 2000000000 + 50;
int A[MAXN];
int mark[MAXN];
int odd_sequence(int L, int R, int n, int k) {
  memset(mark, 0, sizeof(mark));
  int ret = INF;
  while (L <= R) {
    int mid = (L + R) / 2;
    int flag = 0;
    int taken = 0;
    for (int i = 0; i < n; i++) {
      if (flag == 0) {
        if (A[i] <= mid) {
          taken++;
          flag = 1;
        }
      } else {
        flag = 0;
        taken++;
      }
      if (taken == k) break;
    }
    if (taken == k) {
      ret = min(ret, mid);
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return ret;
}
int even_sequence(int L, int R, int n, int k) {
  memset(mark, 0, sizeof(mark));
  int ret = INF;
  while (L <= R) {
    int mid = (L + R) / 2;
    int flag = 0;
    int taken = 0;
    for (int i = 0; i < n; i++) {
      if (flag == 1) {
        if (A[i] <= mid) {
          flag = 0;
          taken++;
        }
      } else {
        flag = 1;
        taken++;
      }
      if (taken == k) break;
    }
    if (taken == k) {
      ret = min(ret, mid);
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return ret;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ret = 1;
    for (int i = 2; i <= n; i++) {
      if (i * 2 <= n) {
        ret = max(ret, 2);
      }
    }
    cout << ret << endl;
  }
  return 0;
}
