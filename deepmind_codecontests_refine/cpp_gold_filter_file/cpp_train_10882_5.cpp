#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t, count = 0;
  cin >> n >> m;
  long long a[200000] = {0};
  for (long long i = 0; i < n; i++) {
    cin >> t;
    if (t < 200000) {
      a[t] = 1;
    }
  }
  t = m;
  for (long long i = 1; t - i >= 0; i++) {
    if (a[i] == 0) {
      t -= i;
      count++;
    }
  }
  cout << count << endl;
  t = m;
  for (long long i = 1; t - i >= 0; i++) {
    if (a[i] == 0) {
      t -= i;
      cout << i << " ";
    }
  }
}
