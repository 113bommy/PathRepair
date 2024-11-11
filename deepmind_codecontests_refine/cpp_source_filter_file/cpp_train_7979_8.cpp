#include <bits/stdc++.h>
using namespace std;
const int maxN = 100010;
int main() {
  int n, m;
  cin >> n >> m;
  int res = n;
  int a[n];
  for (int i = 0; i < int(n); i++) a[i] = 0;
  for (int i = 0; i < int(m); i++) {
    int x;
    cin >> x;
    a[x - 1]++;
  }
  for (int i = 0; i < int(n); i++) res = min(res, a[i]);
  cout << res << endl;
  return 0;
}
