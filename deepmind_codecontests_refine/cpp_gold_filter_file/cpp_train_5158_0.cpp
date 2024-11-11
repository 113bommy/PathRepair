#include <bits/stdc++.h>
using namespace std;
string str;
int e, f;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(5, n / 5), b(5, m / 5);
  for (int i = n - n % 5 + 1; i <= n; i++) a[i % 5]++;
  for (int i = m - m % 5 + 1; i <= m; i++) b[i % 5]++;
  reverse(b.begin() + 1, b.end());
  long long s = 0;
  for (int i = 0; i < 5; i++) {
    s += a[i] * b[i];
  }
  cout << s << endl;
  return 0;
}
