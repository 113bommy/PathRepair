#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  long a[n];
  long min = 0, max = 0;
  for (long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long i = 1; i < n; i++) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) min++;
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) max++;
  }
  cout << min + max;
  return 0;
}
