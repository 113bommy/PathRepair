#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int count = 0;
  int i = n - 1;
  while (m > 0) {
    m = m - a[i];
    count++;
  }
  cout << count;
  return 0;
}
