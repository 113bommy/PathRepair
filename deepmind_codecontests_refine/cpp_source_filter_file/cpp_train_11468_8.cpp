#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int n;
int a, b;
bool ok;
int v[200005];
bool c[200005];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  b = (int)1e9;
  a = -1;
  for (int i = 1; i <= n; i++) {
    if (v[i] > a && v[i] >= b)
      c[i] = 0, a = v[i];
    else if (v[i] < b && v[i] <= a)
      c[i] = 1, b = v[i];
    else if (a <= v[i] && v[i] >= b) {
      cout << "NO";
      return 0;
    } else {
      if (v[i] > v[i + 1])
        b = v[i], c[i] = 1;
      else
        a = v[i], c[i] = 0;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << c[i] << " ";
  return 0;
}
