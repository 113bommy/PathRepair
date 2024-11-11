#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int t, n, m, x = 1, y, p, q, i, j, k, answer = 1;
  cin >> n;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      answer++;
    else
      answer = 1;
    x = max(x, answer);
  }
  cout << n - x;
}
