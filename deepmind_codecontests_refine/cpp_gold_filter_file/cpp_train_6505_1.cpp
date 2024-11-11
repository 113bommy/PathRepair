#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, m, dis;
long long a[100010];
inline bool check(long long mid) {
  long long nowdo = dis, worknum = a[dis];
  for (int i = 0; i < m; i++) {
    long long canwork = mid - nowdo - 1;
    while (canwork >= worknum) {
      if (nowdo == -1) return true;
      canwork -= worknum;
      worknum = a[--nowdo];
      if (nowdo == -1) return true;
    }
    worknum -= canwork;
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 0) dis = i;
  }
  long long lb = 2, ub = 1e18;
  while (lb < ub) {
    long long mid = (lb + ub) / 2;
    if (check(mid))
      ub = mid;
    else
      lb = mid + 1;
  }
  cout << lb << endl;
  return 0;
}
