#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, ni;
  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    return 0;
  }
  t = n / (2 * k + 1);
  if (t * (2 * k + 1) == n)
    ni = t;
  else
    ni = t + 1;
  if (ni == 1) {
    cout << 1 << endl;
    cout << n / 2 << endl;
    return 0;
  }
  vector<int> v(ni);
  int m = n - (ni - 2) * (2 * k + 1);
  int start = m / 2;
  int end = m - start;
  v[0] = start - k;
  v[ni - 1] = n - (end - k - 1);
  int count = ni - 2;
  start = v[0] + 2 * k + 1;
  int i = 1;
  while (count > 0) {
    v[i] = start;
    start = v[i] + 2 * k + 1;
    i++;
    count--;
  }
  cout << ni << endl;
  for (int i = 0; i < ni; i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
