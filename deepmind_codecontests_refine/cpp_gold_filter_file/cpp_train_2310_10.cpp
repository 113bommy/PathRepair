#include <bits/stdc++.h>
using namespace std;
vector<long long> vll;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class TT>
bool pal(T a, TT n) {
  int k = 0;
  for (int i = 0; i <= n / 2; i++) {
    if (a[i] != a[n - i - 1]) {
      k = 1;
      break;
    }
  }
  return k ? 0 : 1;
}
long long powmod(long long a, long long b, long long m = 100000007) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}
int a[88888];
int main() {
  string s;
  cin >> s;
  a[s[0]] = 1;
  cout << "Mike" << '\n';
  for (int i = 1; i < (int)(s).size(); i++) {
    int y = 0;
    for (int j = 'a'; j < s[i]; j++) {
      if (a[j] == 1) {
        y = 1;
        break;
      }
    }
    a[s[i]] = 1;
    if (y == 0)
      cout << "Mike" << '\n';
    else
      cout << "Ann" << '\n';
  }
  getchar();
  getchar();
  return 0;
}
