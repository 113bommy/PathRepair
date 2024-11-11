#include <bits/stdc++.h>
using namespace std;
template <typename T>
T trace2(T a, T b) {
  cerr << a << " " << b << '\n';
}
template <typename T>
T trace3(T a, T b, T c) {
  cerr << a << " " << b << " " << c << '\n';
}
template <typename T>
T trace4(T a, T b, T c, T d) {
  cerr << a << " " << b << " " << c << " " << d << '\n';
}
template <typename T>
T trace5(T a, T b, T c, T d, T e) {
  cerr << a << " " << b << " " << c << " " << d << " " << e << '\n';
}
template <typename T>
T trace6(T a, T b, T c, T d, T e, T f) {
  cerr << a << " " << b << " " << c << " " << d << " " << e << " " << f << '\n';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
template <typename T>
T pow(T a, T b, long long int m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
void swap(long long int *a, long long int *b) {
  long long int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
void fuck() {
  long long int x, y, z, x1, y1, z1;
  cin >> x >> y >> z >> x1 >> y1 >> z1;
  long long int a[7];
  for (__typeof(6 + 1) i = (1) - ((1) > (6 + 1));
       i != (6 + 1) - ((1) > (6 + 1)); i += 1 - 2 * ((1) > (6 + 1)))
    cin >> a[i];
  long long int ans = 0;
  if (y < 0) {
    ans += a[1];
  }
  if (y > y1) ans += a[2];
  if (z < 0) ans += a[3];
  if (z > z1) ans += a[4];
  if (x < 0) ans += a[5];
  if (x > x1) ans += a[6];
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  fuck();
  return 0;
}
