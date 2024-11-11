#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n;
  cin >> n;
  memset(a, -1, 100001 * sizeof(int));
  string str = "YES\n";
  for (int i = 0; i < n; ++i) {
    int x, k;
    cin >> x >> k;
    if (a[k] + 1 == x) ++a[k];
    if (a[k] < x) str = "NO\n";
  }
  cout << str;
  return 0;
}
