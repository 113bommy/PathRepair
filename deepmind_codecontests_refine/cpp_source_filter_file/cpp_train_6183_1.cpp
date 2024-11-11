#include <bits/stdc++.h>
using namespace std;
void print(long long int n) { cout << n << ' '; }
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
void print(long long int a[], int i, int n) {
  for (; i < n; i++) {
    cout << a[i] << ' ';
  }
}
void printv(vector<int> v, int i, int n) {
  for (; i < n; i++) {
    cout << v[i] << ' ';
  }
}
void gett(long long int a[], int i, int n) {
  for (; i < n; i++) {
    cin >> a[i];
  }
}
void line() { cout << '\n'; }
void prime(bool bo[], vector<int> pri) {
  for (int i = 2; i < 1000009; i++) {
    if (bo[i]) continue;
    pri.push_back(i);
    for (int j = i * 2; j < 1000009; j += i) {
      bo[j] = 'True';
    }
  }
}
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
const double PI = 3.14159265;
double l, d, v, g, r;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> l >> d >> v >> g >> r;
  double t1 = d / v, t2, t3;
  int i;
  for (i = 0, t2 = 0; t2 < t1; (i % 2 ? t2 += r : t2 += g), i++)
    ;
  if (i % 2) t2 = t1;
  t3 = t2 + (l - d) / v;
  cout << fixed << setprecision(8) << t3 << '\n';
  return 0;
}
