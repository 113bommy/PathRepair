#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n0, n1, a00, a01, a10, a11;
int find(int x) {
  if (x == 0) return 0;
  for (long long i = 2; (i * (i - 1) / 2) < maxn; i++)
    if (i * (i - 1) / 2 == x) return i;
  cout << "Impossible\n";
  exit(0);
}
int main() {
  cin >> a00 >> a01 >> a10 >> a11;
  n0 = find(a00);
  n1 = find(a11);
  if (!n0 && (a01 || a10)) n0 = 1;
  if (!n1 && (a10 || a01)) n1 = 1;
  if (!a10 && !a01) {
    if (n1 && n0) {
      cout << "Impossible\n";
      return 0;
    }
    for (int i = 0; i < n0; i++) cout << 0;
    for (int i = 0; i < n1; i++) cout << 1;
    if (!n1 && !n0) cout << 1;
    cout << "\n";
    return 0;
  }
  if (a01 + a10 != n0 * n1) {
    cout << "Impossible\n";
    return 0;
  }
  int n = n0 + n1;
  for (int i = 0; i < n; i++)
    if (n0 && n1 <= a01) {
      cout << 0;
      n0--;
      a01 -= n1;
    } else {
      cout << 1;
      n1--;
      a10 -= n0;
    }
  cout << "\n";
  return 0;
}
