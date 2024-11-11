#include <bits/stdc++.h>
using namespace std;
long int i, n, s, x, c[100001];
int main() {
  cin >> n >> x;
  for (i = 1; i <= n; i++) cin >> c[i];
  sort(c + 1, c + n + 1);
  for (i = 1; i <= n; i++) {
    s = s + x * c[i];
    if (x > 1) x--;
  }
  cout << s;
}
