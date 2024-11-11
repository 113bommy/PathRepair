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
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
long long int a;
long long int tens[20];
int main() {
  tens[0] = 1;
  for (int i = 0; i < (19); ++i) tens[i + 1] = tens[i] * 10;
  long long int L = tens[18], R = L * 2;
  cin >> a;
  long long int sum = 17 * tens[17] % a * 4 % a * 5 % a;
  sum = sum + tens[18];
  sum %= a;
  L -= sum;
  R -= sum;
  cout << L << ' ' << R - 1 << endl;
  return 0;
}
