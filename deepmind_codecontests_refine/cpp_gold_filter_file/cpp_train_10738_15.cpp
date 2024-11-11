#include <bits/stdc++.h>
using namespace std;
int n, k, A[200002];
bool check(int x) {
  int ans = 0;
  for (int i = 0; i < x; i++) {
    if (A[n - x + i] - A[i] >= k) ans++;
  }
  return ans == x;
}
int bs() {
  int lo = 0, hi = n / 2, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  cout << bs() << endl;
}
