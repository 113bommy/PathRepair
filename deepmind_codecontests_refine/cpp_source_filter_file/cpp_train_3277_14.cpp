#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n, a[200005], i, x, m;
int main() {
  cin >> (s + 1);
  n = strlen(s + 1);
  cin >> m;
  for (; m; m--) {
    cin >> x;
    a[x]++;
    a[n - x + 1]--;
  }
  for (i = 1; i <= n; i++) a[i] += a[i - 1];
  for (i = 1; i <= n; i++)
    if (a[i] & 1) swap(s[i], s[n - i + 1]);
  cout << (s + 1);
}
