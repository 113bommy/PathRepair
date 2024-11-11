#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n], count = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 2)
    cout << 0 << "\n";
  else {
    sort(a, a + n);
    for (long long int i = 0; i < n; i++) {
      if ((a[i] != a[0]) && (a[i] != a[n - 1])) ++count;
    }
    cout << count - 1 << "\n";
  }
}
