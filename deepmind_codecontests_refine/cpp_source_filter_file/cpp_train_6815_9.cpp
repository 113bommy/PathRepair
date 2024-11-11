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
const long long int N = 1e6 + 10;
void f() {
  string s;
  cin >> s;
  if (s.length() <= 1) {
    cout << "NO";
    return;
  }
  long long int a, b;
  cin >> a >> b;
  std::vector<long long int> rema(N);
  std::vector<long long int> remb(N);
  long long int temp = 0;
  rema[0] = (s[0] - '0') % a;
  for (__typeof(s.length()) i = (1) - ((1) > (s.length()));
       i != (s.length()) - ((1) > (s.length()));
       i += 1 - 2 * ((1) > (s.length()))) {
    rema[i] = (rema[i - 1] * 10 + (s[i] - '0')) % a;
  }
  long long int x = 10;
  remb[s.length() - 1] = (s[s.length() - 1] - '0');
  for (long long int i = s.length() - 2; i >= 0; i--) {
    remb[i] = (remb[i + 1] % b + (((s[i] - '0') % b) * x) % b) % b;
    x *= 10;
    x = x % b;
  }
  for (long long int i = 0; i + 1 < s.length(); i++) {
    if (rema[i] == 0 && remb[i + 1] == 0 && s[i + 1] != '0') {
      cout << "YES" << '\n';
      for (__typeof(s.length()) j = (0) - ((0) > (s.length()));
           j != (s.length()) - ((0) > (s.length()));
           j += 1 - 2 * ((0) > (s.length()))) {
        if (j == i + 1) cout << '\n';
        cout << s[j];
      }
      return;
    }
  }
  cout << "NO";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  f();
  return 0;
}
