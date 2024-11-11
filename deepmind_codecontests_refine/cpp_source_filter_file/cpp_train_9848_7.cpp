#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, s;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < k; i++) s = s + a[i];
  cout << s;
  return 0;
}
