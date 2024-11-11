#include <bits/stdc++.h>
using namespace std;
inline void read_string_to_vector(vector<string> &vec) {
  string str;
  getline(cin, str);
  vec.push_back(str);
}
template <typename T>
inline void read_digit_to_vector(vector<T> &vec) {
  T t;
  cin >> t;
  vec.push_back(t);
}
long long n, m, k;
int main() {
  ios::sync_with_stdio(false);
  scanf("%lld %lld %lld", &n, &m, &k);
  if (n & 1) {
    bool ok = false;
    for (register long long i = 2; i * i <= m; ++i) {
      if (!(m % i) && (i >= k || (m / i) >= k)) {
        ok = true;
        break;
      }
    }
    if (m > 1 && k == 1) ok = true;
    if (ok)
      printf("Timur\n");
    else
      printf("Marsel\n");
  } else
    printf("Marsel\n");
  return 0;
}
