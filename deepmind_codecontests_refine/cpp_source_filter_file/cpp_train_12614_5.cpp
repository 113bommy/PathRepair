#include <bits/stdc++.h>
using namespace std;
long long n, a[100999], k, sum;
string p1 = "sjfnb", p2 = "cslnb";
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  for (long long i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      k++;
      if (k == 2 || (i > 0 && a[i] == a[i - 1]) || a[i] == 0) {
        cout << "cslnb";
        return 0;
      }
    }
  }
  if (sum % 2 == ((n * (n - 1)) / 2) % 2)
    cout << p2;
  else
    cout << p1;
}
