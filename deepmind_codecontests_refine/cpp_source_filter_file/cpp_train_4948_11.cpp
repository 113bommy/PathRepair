#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  int b[n];
  for (i = 0; i < n; i++) cin >> b[i];
  vector<int> c, d;
  for (i = 0; i < n; i++) {
    if (a[i] != 0) c.push_back(a[i]);
    if (b[i] != 0) d.push_back(b[i]);
  }
  n--;
  for (i = 0; i < n; i++) c.push_back(a[i]);
  for (i = 0; i < n; i++) d.push_back(d[i]);
  for (i = 0; i < n; i++)
    if (c[i] == d[0]) break;
  int flag = 0;
  for (int j = i + 1; j < 2 * n; j++) {
    if (c[j] != d[j - i]) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
