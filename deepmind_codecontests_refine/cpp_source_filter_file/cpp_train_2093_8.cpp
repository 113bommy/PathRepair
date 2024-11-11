#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, r, a[179];
char x;
int main() {
  for (cin >> n; i < n; i++) cin >> x;
  a[i + 1] = a[i] + x - '0';
  for (i = 1; i < n; i++)
    for (k = i, j = i + 1l; j <= n; j++)
      if (a[j] - a[k] == a[i]) a[j] == a[n] ? r = 1 : k = j;
  cout << (r ? "YES" : "NO");
}
