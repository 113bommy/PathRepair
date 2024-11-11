#include <bits/stdc++.h>
using namespace std;
const unsigned long long pow2[64] = {1,
                                     2,
                                     4,
                                     8,
                                     16,
                                     32,
                                     64,
                                     128,
                                     256,
                                     512,
                                     1024,
                                     2048,
                                     4096,
                                     8192,
                                     16384,
                                     32768,
                                     65536,
                                     131072,
                                     262144,
                                     524288,
                                     1048576,
                                     2097152,
                                     4194304,
                                     8388608,
                                     16777216,
                                     33554432,
                                     67108864,
                                     134217728,
                                     268435456,
                                     536870912,
                                     1073741824,
                                     2147483648,
                                     4294967296,
                                     8589934592,
                                     17179869184,
                                     34359738368,
                                     68719476736,
                                     137438953472,
                                     274877906944,
                                     549755813888,
                                     1099511627776,
                                     2199023255552,
                                     4398046511104,
                                     8796093022208,
                                     17592186044416,
                                     35184372088832,
                                     70368744177664,
                                     140737488355328,
                                     281474976710656,
                                     562949953421312,
                                     1125899906842624,
                                     2251799813685248,
                                     4503599627370496,
                                     9007199254740992,
                                     18014398509481984,
                                     36028797018963968,
                                     72057594037927936,
                                     144115188075855872,
                                     288230376151711744,
                                     576460752303423488,
                                     1152921504606846976,
                                     2305843009213693952,
                                     4611686018427387904,
                                     9223372036854775808};
const long long mod = 1000000007;
const string clear = "\x1B[2J\x1B[H";
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
template <typename T>
inline void print_array(const vector<T>& array) {
  for (size_t i = 0; i < array.size(); ++i) cout << array[i] << ' ';
  cout << endl;
}
template <typename T>
inline void print_matrix(const vector<vector<T>>& matrix, ofstream) {
  for (size_t i = 0; i < matrix.size(); ++i) print_array(matrix[i]);
  cout << endl;
}
inline long double logn(const long double& n, const long double& base) {
  return log(n) / log(base);
}
inline long long pown(long long n, long long power) {
  long long res = 1;
  while (power) {
    if (power & 1) res *= n;
    n *= n;
    power >>= 1;
  }
  return res;
}
int32_t main() {
  boostIO();
  long long t, a, b, ans, tmp;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    cin >> a >> b;
    if (b > a) swap(a, b);
    ans = min(a - b, b);
    a -= ans;
    b -= ans;
    ans += 2 * min(a / 3, b / 3);
    a %= 3;
    b %= 3;
    if (a > 1 && b > 0) ++ans;
    cout << ans << endl;
  }
  cout.flush();
  getchar();
  return 0;
}
