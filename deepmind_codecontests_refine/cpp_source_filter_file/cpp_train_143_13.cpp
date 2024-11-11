#include <bits/stdc++.h>
using namespace std;
long long Ans[5002], A[5002], add[5002], l[5002], r[5002], k[5002], d[5002];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= 5001; i++) A[i] = -0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < m; i++) {
    cin >> k[i] >> l[i] >> r[i] >> d[i];
    if (k[i] == 1)
      for (int j = l[i]; j <= r[i]; j++) add[j] += d[i];
    else {
      int flag = 0;
      for (int j = l[i]; j <= r[i]; j++)
        if (A[j] != -0x3f3f3f3f3f3f3f3f && d[i] > A[j] + add[j])
          continue;
        else
          A[j] = d[i] - add[j], flag = 1;
      if (flag == 0) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  for (int i = 0; i <= 5001; i++) Ans[i] = A[i];
  for (int i = 0; i < m; i++) {
    if (k[i] == 1)
      for (int j = l[i]; j <= r[i]; j++) A[j] += d[i];
    else {
      int ans = -0x3f3f3f3f3f3f3f3f;
      for (int j = l[i]; j <= r[i]; j++)
        if (A[j] > ans) ans = A[j];
      if (ans > d[i]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++)
    if (Ans[i] != -0x3f3f3f3f3f3f3f3f)
      cout << Ans[i] << " ";
    else
      cout << 0 << " ";
  return 0;
}
