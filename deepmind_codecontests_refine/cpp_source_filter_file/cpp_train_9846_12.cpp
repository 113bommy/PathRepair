#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sum = 0;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  for (long long int i = 1; i < n; i++) sum += a[1] - a[i];
  cout << sum << endl;
}
