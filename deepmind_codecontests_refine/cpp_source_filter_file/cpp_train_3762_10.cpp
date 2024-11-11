#include <bits/stdc++.h>
using namespace std;
unsigned long long i, j;
long long n, h;
unsigned long long sum;
long a[200000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  h = n >> 1;
  for (i = 0; i < h; i++) {
    sum += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
  }
  cout << sum << endl;
  return 0;
}
