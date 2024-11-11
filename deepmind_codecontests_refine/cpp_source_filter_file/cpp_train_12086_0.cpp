#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxi = -1, c;
  cin >> n;
  long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    c = 1;
    int k = i + 1;
    while (a[i] == a[k] && k < n) {
      c++;
      k++;
    }
    i = k;
    maxi = max(maxi, c);
  }
  cout << n - maxi;
}
