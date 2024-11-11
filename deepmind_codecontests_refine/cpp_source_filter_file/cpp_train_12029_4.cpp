#include <bits/stdc++.h>
using namespace std;
int a = 1234567, b = 123456, c = 1234;
long long n;
vector<long long> x, y, v;
int main() {
  x.clear();
  y.clear();
  v.clear();
  cin >> n;
  bool ans = 0;
  for (int i = 0; i <= n && !ans; i++) {
    long long num = 1ll * i * a;
    if (num == n) ans = 1;
    if (num >= n) break;
    x.push_back(num);
  }
  if (ans) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i <= n && !ans; i++) {
    long long num = 1ll * i * b;
    if (num == n) ans = 1;
    if (num >= n) break;
    y.push_back(num);
  }
  if (ans) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < x.size(); i++)
    for (int j = 0; j < y.size(); j++) {
      long long tmp = x[i] + y[i];
      if (n - tmp >= c && (n - tmp) % c == 0) ans = 1;
      if (tmp == n) ans = 1;
    }
  for (int i = 0; i < x.size() && !ans; i++)
    if (n - x[i] >= c && (n - x[i]) % c == 0) ans = 1;
  for (int i = 0; i < y.size() && !ans; i++)
    if (n - y[i] >= c && (n - y[i]) % c == 0) ans = 1;
  if (n >= c && n % c == 0) ans = 1;
  puts(ans ? "YES" : "NO");
}
