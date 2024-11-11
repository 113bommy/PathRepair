#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, t, a[30000], sum = 0;
  cin >> n >> t;
  for (int i = 1; i < n; i++) cin >> a[i];
  i = 1;
  while (i <= t) {
    if (a[i] + i == t) sum++;
    i++;
  }
  if (sum != 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
