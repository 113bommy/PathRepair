#include <bits/stdc++.h>
using namespace std;
long long a[100100];
long long sol[100100];
long long sol2[100100];
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sol[0] = min(1LL, max(a[0], 0LL));
  for (int i = 1; i < n; i++) {
    sol[i] = min((long long)i + 1, min(a[i], sol[i - 1] + 1));
  }
  sol2[n - 1] = min(1LL, max(a[n - 1], 0LL));
  long long vv = 2;
  for (int i = n - 2; i >= 0; i--) {
    sol2[i] = min((long long)vv, min(a[i], sol2[i + 1] + 1));
    vv++;
  }
  long long tt = 0;
  for (int i = 0; i < n; i++) {
    tt = max(min(sol[i], sol2[i]), tt);
  }
  cout << tt << endl;
  return 0;
}
