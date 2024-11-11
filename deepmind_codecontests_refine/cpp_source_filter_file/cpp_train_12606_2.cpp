#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c = 0, j = 0;
  cin >> n >> m;
  int a[n], b[n], d[n];
  long long int s = 0, s1 = 0, td = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    d[i] = a[i] - b[i];
    td += a[i];
    s += a[i];
    s1 += b[i];
  }
  sort(d, d + n);
  reverse(d, d + n);
  td -= m;
  if (s <= m)
    c = 0;
  else if (s1 >= m)
    c = -1;
  else {
    while (td > 0) {
      td -= d[j];
      c++;
      j++;
    }
  }
  cout << c << endl;
  return 0;
}
