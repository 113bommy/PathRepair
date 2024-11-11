#include <bits/stdc++.h>
using namespace std;
int n, a[1505], m;
bool p;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] > a[j]) p = !p;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    if ((r - l + 1) % 4 && (r - l) % 4) p = !p;
    if (!p)
      cout << "even\n";
    else
      cout << "odd\n";
  }
}
