#include <bits/stdc++.h>
using namespace std;
long long n, m, c, inp, i;
vector<int> a(1005);
int main() {
  cin >> n >> m >> c;
  while (m--) {
    cin >> inp;
    if (inp < c / 2)
      for (i = 1; i <= n && a[i] <= inp && a[i]; i++)
        ;
    else
      for (i = n; i >= 1 && a[i] >= inp && a[i]; i--)
        ;
    a[i] = inp;
    cout << i << endl;
    for (i = 1; i <= n; i++)
      if (!a[i]) break;
    if (i > n) return 0;
    fflush(stdout);
  }
  return 0;
}
