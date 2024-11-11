#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long int res = 0;
  long long int m1 = 0, m2 = 0, m = 0;
  int tmp;
  for (int i = 0; i < n;) {
    tmp = a[i];
    res = 1;
    ++i;
    while (tmp == a[i] && i < n) {
      ++res;
      ++i;
    }
    if (tmp == 1)
      m1 = res;
    else
      m2 = res;
    m = min(m1, m2);
  }
  cout << m * 2;
  return 0;
}
