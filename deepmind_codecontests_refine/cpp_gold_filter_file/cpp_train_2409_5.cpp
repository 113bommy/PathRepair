#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[100001];
  long long m = 0, ma = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] != m) continue;
    long long count = 0;
    while (a[i] == m && i < n) {
      count++;
      i++;
    }
    ma = max(ma, count);
  }
  cout << ma << endl;
  return 0;
}
