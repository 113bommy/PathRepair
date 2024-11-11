#include <bits/stdc++.h>
using namespace std;
int n, res = 0;
pair<int, int> A[5001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i].first >> A[i].second;
  sort(A + 1, A + n + 1);
  for (int i = 1; i <= n; i++) {
    if (res <= A[i].second)
      res = A[i].second;
    else
      res = A[i].first;
  }
  cout << res;
  return 0;
}
