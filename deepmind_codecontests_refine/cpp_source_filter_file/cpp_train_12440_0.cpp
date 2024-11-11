#include <bits/stdc++.h>
using namespace std;
long long int maxx, l, k, minn, w, d, n, m, x, z, g[100001], y, c[100001],
    a[100001], b[100001], p;
string s;
bool mark[100001];
long long int f(long long int n) {
  while (n % 3 == 0) n = n / 3;
  while (n % 2 == 0) n = n / 2;
  return n;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    x = f(x);
    a[i] = x;
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
