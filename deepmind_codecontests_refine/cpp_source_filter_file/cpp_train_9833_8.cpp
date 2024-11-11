#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
int n, m;
int main() {
  cin >> n >> m;
  if (n * m - 1 == 0) {
    printf("%.10f\n", 1.0);
    return 0;
  }
  double res = 1.0 / n + 1.0 * (n - 1) / n / (n * m - 1) * (n - 1);
  printf("%.10f\n", res);
  return 0;
}
