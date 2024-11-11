#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);
template <class T>
void smin(T& a, T b) {
  if (a > b) a = b;
}
template <class T>
void smax(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << p.first << ',' << p.second;
  return out;
}
template <class T>
void outp(const vector<T>& v) {
  cout << int((v).size()) << ":";
  for (int i(0), _b(int((v).size())); i < _b; ++i) cout << " " << v[i];
  cout << endl;
}
template <class T>
void outp(T* v, int n) {
  cout << n << ":";
  for (int i(0), _b(n); i < _b; ++i) cout << " " << *v++;
  cout << endl;
}
int n;
int main() {
  scanf("%d", &n);
  if (n == 5) {
    printf("1 2 2\n2 3 1\n1 4 1\n4 5 1\n");
    printf("2 3\n2 4\n");
  } else {
    int m = n / 2;
    for (int i(1), _b(m + 1); i < _b; ++i) printf("%d %d 1\n", i, i + m);
    for (int i(m + 1), _b(n); i < _b; ++i)
      printf("%d %d %d\n", i, i + 1, 2 * (i - m) - 1);
    for (int i(1), _b(m); i < _b; ++i) printf("%d %d\n", i, i + 1);
    printf("1 3\n");
  }
  return 0;
}
