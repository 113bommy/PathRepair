#include <bits/stdc++.h>
const int N = 1e5 + 7;
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> a(n, 0);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 2) {
    cout << n << endl;
    return 0;
  }
  long long int l = -1, r = -1;
  long long int L[N] = {0}, R[N] = {0};
  for (long long int i = 0; i < n; i++) {
    if (i > l) {
      l = i;
      while (l < n - 1 && a[l] < a[l + 1]) l++;
      R[i] = l;
    } else {
      R[i] = l;
    }
  }
  r = n;
  for (long long int i = n - 1; ~i; i--) {
    if (r > i) {
      r = i;
      while (r > 0 && a[r] > a[r - 1]) r--;
      L[i] = r;
    } else {
      L[i] = r;
    }
  }
  long long int ans = 1;
  for (int i = 0; i < n; i++) {
    bool cando = false;
    ans = max({ans, i - L[i] + 2, R[i] - i + 2});
    if (i > 0 && i < n - 1 && a[i - 1] + 1 < a[i + 1]) cando = true;
    if (cando) ans = max({ans, R[i + 1] - L[i - 1] + 1});
  }
  cout << min(n, ans) << endl;
  return 0;
}
