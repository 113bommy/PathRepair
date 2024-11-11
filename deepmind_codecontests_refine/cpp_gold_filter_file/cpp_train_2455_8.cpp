#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, j;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[(n / 2)];
}
