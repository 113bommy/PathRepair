#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
template <class T>
void print(T& x) {
  cout << x;
}
template <class T, class U>
void print(pair<T, U>& p) {
  cout << "(";
  print(p.first);
  cout << ", ";
  print(p.second);
  cout << ")";
}
template <class T>
void print(vector<T>& v) {
  cout << "{";
  if (((int)(v).size())) print(v[0]);
  for (int i = 1; i < ((int)(v).size()); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}
int n, m, T;
long long f(long long k, long long a, long long b, long long d) {
  return -k * a + b * d * (k * (k - 1)) / 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c * b)
      cout << -1 << endl;
    else if (d >= c)
      cout << a << endl;
    else {
      long long t = a / b;
      cout << -min(-a, f(t / d, a, b, d)) << endl;
    }
  }
  return 0;
}
