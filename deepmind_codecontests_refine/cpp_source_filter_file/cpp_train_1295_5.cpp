#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int i, n, k, s;
  cin >> s >> n;
  for (i = 1, k = 0; i <= n; i++) {
    long x = i & -i;
    if (s - x == 0) {
      a[k] = i;
      s = s - x;
      k++;
      break;
    } else if (s - x < 0)
      continue;
    a[k] = i;
    s = s - x;
    k++;
  }
  if (s)
    cout << "-1" << endl;
  else {
    cout << k << endl;
    for (i = 0; i < k; i++) cout << a[i] << " ";
  }
  return 0;
}
