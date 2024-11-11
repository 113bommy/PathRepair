#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  cin >> a[0];
  int A = 0, B = 0;
  int minn = a[0], maxx = a[0];
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    if (a[i] > maxx) {
      maxx = a[i];
      A = i;
    }
    if (a[i] < minn) {
      minn = a[i];
      B = i;
    }
  }
  if (A > B) swap(A, B);
  cout << max(B - A, max(n - 1 - A, B));
  return 0;
}
