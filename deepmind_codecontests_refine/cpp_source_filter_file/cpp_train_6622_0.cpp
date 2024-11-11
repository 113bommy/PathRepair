#include <bits/stdc++.h>
using namespace std;
long long A[100001], n, k, sum;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  long long L = 0, R = 1000000000, M, ans = -1;
  while (L < R) {
    M = (L + R) >> 1;
    sum = 0;
    for (int i = 1; i <= n; ++i) sum += min(A[i], M);
    if (sum >= k) {
      ans = M;
      if (sum == k) {
        break;
      }
      R = M;
    } else
      L = M + 1;
  }
  if (ans != -1) {
    vector<int> prints, printf;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += min(A[i], ans - 1);
      A[i] -= min(A[i], ans - 1);
    }
    for (int i = 1; i <= n; ++i) {
      if (A[i]) {
        if (sum + 1 > k)
          printf.push_back(i);
        else if (A[i] > 1)
          prints.push_back(i);
        ++sum;
      }
    }
    for (int i = 0; i < printf.size(); ++i) {
      cout << printf[i] << " ";
    }
    for (int i = 0; i < prints.size(); ++i) {
      cout << prints[i] << " ";
    }
  } else
    printf("-1");
  return 0;
}
