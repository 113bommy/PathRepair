#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, n1 = 0, n2 = 0, ar = 0, curr = 0, current;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  current = a[0];
  for (i = 0; i < n; i++) {
    if (curr == 0 && a[i] == current)
      n1++;
    else if (a[i] != current)
      curr++, n2++;
    if ((curr > 0 && a[i] == current) || i == n - 1) {
      current = a[i - 1];
      if (n1 == n2)
        ar = max(n1 + n2, ar);
      else
        ar = max((2 * min(n1, n2)), ar);
      n1 = n2, n2 = 1;
    }
  }
  cout << ar << endl;
  return 0;
}
