#include <bits/stdc++.h>
using namespace std;
int n, A[1003];
int MAXS = 20002;
int ans = INT_MAX, a, D;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  for (int d = 0; d <= MAXS; d++) {
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      mini = min(mini, A[i] - i * d);
      maxi = max(maxi, A[i] - i * d);
    }
    int mid = (maxi + mini) / 2;
    int here = max(maxi - mid, mid - mini);
    if (ans > here) {
      ans = here, a = mid, D = d;
    }
  }
  cout << ans << endl;
  cout << a << " " << D << endl;
  return 0;
}
