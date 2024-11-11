#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, j, i, k, a[311111];
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  i = 0;
  j = n - 1;
  int sum = 0, cnt = 0;
  while (i < j) {
    k = a[i++] + a[j--];
    sum += (k * k);
  }
  cout << sum;
}
