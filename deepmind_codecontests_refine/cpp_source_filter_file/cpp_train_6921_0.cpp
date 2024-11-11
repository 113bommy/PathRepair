#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long q = 0, w = 0;
  for (int i = 0; i < n; i++) {
    if (q <= a[i]) w++;
    q = q + a[i];
  }
  cout << w;
}
