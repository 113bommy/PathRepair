#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  int n;
  cin >> n;
  ;
  int A[100000];
  int max = 0;
  for (int i = (1); i < n + 1; i++) {
    cin >> A[i];
    if (A[i] > max) max = A[i];
  }
  int pos = 1;
  int ans = max + 1;
  for (int i = (1); i < max + 1; i++) {
    pos = 1;
    while (pos < n) {
      if (A[1] < i) {
        ans = min(i, ans);
        break;
      }
      if (A[n] < i) {
        ans = min(i, ans);
        break;
      }
      if (A[pos + 1] >= i) {
        pos++;
      } else if (A[pos + 2] >= i)
        pos++;
      else {
        ans = min(ans, i);
        break;
      }
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
