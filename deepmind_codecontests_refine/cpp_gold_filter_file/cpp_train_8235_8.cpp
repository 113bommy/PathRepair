#include <bits/stdc++.h>
using namespace std;
int T, a, b;
bool case30(int n, int m, int t) {
  if (t) swap(n, m);
  if (n < 75) return false;
  int a[] = {-1, 25, 25, 25, 0, 0};
  int b[] = {-1, 0, 0, 0, 0, 0};
  n -= 75;
  b[1] = min(m, 23);
  m -= min(m, 23);
  int tmp = min(n, m);
  a[1] += tmp;
  b[1] += tmp;
  m -= tmp;
  n -= tmp;
  b[2] += min(m, 23);
  m -= min(m, 23);
  b[3] += min(m, 23);
  m -= min(m, 23);
  if (m > 0 || n > 0) return false;
  if (t == 0)
    cout << "3:0\n";
  else
    cout << "0:3\n";
  if (t)
    for (int i = (int)1; i <= (int)3; ++i) swap(a[i], b[i]);
  for (int i = (int)1; i <= (int)3; ++i) cout << a[i] << ':' << b[i] << ' ';
  ;
  cout << '\n';
  return true;
}
bool case31_a(int n, int m, int t) {
  if (t) swap(n, m);
  if (n < 75 || m < 25) return false;
  int a[] = {-1, 25, 25, 25, 0, 0};
  int b[] = {-1, 0, 0, 0, 25, 0};
  n -= 75;
  m -= 25;
  a[4] += min(n, 23);
  n -= min(n, 23);
  int tmp = min(n, m);
  a[4] += tmp;
  b[4] += tmp;
  n -= tmp;
  m -= tmp;
  b[1] += min(m, 23);
  m -= min(m, 23);
  b[2] += min(m, 23);
  m -= min(m, 23);
  b[3] += min(m, 23);
  m -= min(m, 23);
  if (m > 0 || n > 0) return false;
  if (t == 0)
    cout << "3:1\n";
  else
    cout << "1:3\n";
  swap(a[3], a[4]);
  swap(b[3], b[4]);
  if (t)
    for (int i = (int)1; i <= (int)4; ++i) swap(a[i], b[i]);
  for (int i = (int)1; i <= (int)4; ++i) cout << a[i] << ':' << b[i] << ' ';
  ;
  cout << '\n';
  return true;
}
bool case31_b(int n, int m, int t) {
  if (t) swap(n, m);
  if (n < 75 || m < 25) return false;
  int a[] = {-1, 25, 25, 25, 0, 0};
  int b[] = {-1, 0, 0, 0, 25, 0};
  n -= 75;
  m -= 25;
  b[1] += min(m, 23);
  m -= min(m, 23);
  int tmp = min(n, m);
  a[1] += tmp;
  b[1] += tmp;
  n -= tmp;
  m -= tmp;
  b[2] += min(m, 23);
  m -= min(m, 23);
  b[3] += min(m, 23);
  m -= min(m, 23);
  a[4] += min(n, 23);
  n -= min(n, 23);
  if (m > 0 || n > 0) return false;
  if (t == 0)
    cout << "3:1\n";
  else
    cout << "1:3\n";
  swap(a[3], a[4]);
  swap(b[3], b[4]);
  if (t)
    for (int i = (int)1; i <= (int)4; ++i) swap(a[i], b[i]);
  for (int i = (int)1; i <= (int)4; ++i) cout << a[i] << ':' << b[i] << ' ';
  ;
  cout << '\n';
  return true;
}
bool case32_a(int n, int m, int t) {
  if (t) swap(n, m);
  if (n < 65 || m < 50) return false;
  int a[] = {-1, 25, 25, 0, 0, 15, 0};
  int b[] = {-1, 0, 0, 25, 25, 0, 0};
  n -= 65;
  m -= 50;
  b[5] = min(m, 13);
  m -= min(m, 13);
  int tmp = min(n, m);
  a[5] += tmp;
  b[5] += tmp;
  n -= tmp;
  m -= tmp;
  a[3] += min(n, 23);
  n -= min(n, 23);
  a[4] += min(n, 23);
  n -= min(n, 23);
  b[1] += min(m, 23);
  m -= min(m, 23);
  b[2] += min(m, 23);
  m -= min(m, 23);
  if (n > 0 || m > 0) return false;
  if (t == 0)
    cout << "3:2\n";
  else
    cout << "2:3\n";
  if (t)
    for (int i = (int)1; i <= (int)5; ++i) swap(a[i], b[i]);
  for (int i = (int)1; i <= (int)5; ++i) cout << a[i] << ':' << b[i] << ' ';
  cout << '\n';
  return true;
}
bool case32_b(int n, int m, int t) {
  if (t) swap(n, m);
  if (n < 65 || m < 50) return false;
  int a[] = {-1, 25, 25, 0, 0, 15, 0};
  int b[] = {-1, 0, 0, 25, 25, 0, 0};
  n -= 65;
  m -= 50;
  a[3] = min(n, 23);
  n -= min(n, 23);
  int tmp = min(n, m);
  a[3] += tmp;
  b[3] += tmp;
  n -= tmp;
  m -= tmp;
  a[4] += min(n, 23);
  n -= min(n, 23);
  b[1] += min(m, 23);
  m -= min(m, 23);
  b[2] += min(m, 23);
  m -= min(m, 23);
  b[5] += min(m, 13);
  m -= min(m, 13);
  if (n > 0 || m > 0) return false;
  if (t == 0)
    cout << "3:2\n";
  else
    cout << "2:3\n";
  if (t)
    for (int i = (int)1; i <= (int)5; ++i) swap(a[i], b[i]);
  for (int i = (int)1; i <= (int)5; ++i) cout << a[i] << ':' << b[i] << ' ';
  cout << '\n';
  return true;
}
void solve() {
  if (case30(a, b, 0)) return;
  if (case31_a(a, b, 0)) return;
  if (case31_b(a, b, 0)) return;
  if (case32_a(a, b, 0)) return;
  if (case32_b(a, b, 0)) return;
  if (case32_a(a, b, 1)) return;
  if (case32_b(a, b, 1)) return;
  if (case31_a(a, b, 1)) return;
  if (case31_b(a, b, 1)) return;
  if (case30(a, b, 1)) return;
  cout << "Impossible\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> a >> b;
    solve();
  }
}
