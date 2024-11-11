#include <bits/stdc++.h>
using namespace std;
long long a[1000];
int main() {
  int n, i, k;
  long long count = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  count += a[1];
  for (i = 2; i <= n; i++) {
    count += (a[i] - 1) * i;
    count += 1;
  }
  cout << count;
  return (0);
}
