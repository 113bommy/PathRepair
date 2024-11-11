#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long a = n % 6, b = m % 6;
  long long ans = (n * m - a * b);
  if (n % 6 == 0 || m % 6 == 0) {
    cout << n * m << '\n';
    return 0;
  } else if (n % 2 == 0 || m % 2 == 0) {
    if (n % 2 == 0 && m % 4 == 0 || n % 4 == 0 && m % 2 == 0) {
      cout << m * n << '\n';
      return 0;
    }
    if (n % 2 == 0 && m % 5 == 0 || n % 5 == 0 && m % 2 == 0) {
      cout << m * n << '\n';
      return 0;
    }
    if (m % 2 == 0) {
      swap(n, m);
      swap(a, b);
    }
    if (m == 1)
      cout << n / 6 * 6 + 2 * (n % 6 >= 4) + 2 * (n % 6 >= 5) << '\n';
    else if (m == 2)
      if (n == 2)
        cout << 0 << '\n';
      else
        cout << n * m << '\n';
    else if (m == 3)
      if (n == 2)
        cout << 4 << '\n';
      else
        cout << n * m << '\n';
    else if (m == 7)
      if (n == 2)
        cout << 14 << '\n';
      else
        cout << n * m << '\n';
    else if (m == 11)
      if (n == 2)
        cout << 22 << '\n';
      else
        cout << n * m << '\n';
    else
      cout << n * m << '\n';
  } else {
    if (n % 5 == 0 || m % 5 == 0) {
      cout << m * n - 1 << '\n';
      return 0;
    }
    if (n == 1 || m == 1) {
      n *= m;
      cout << n / 6 * 6 + 2 * (n % 6 >= 4) + 2 * (n % 6 >= 5) << '\n';
      return 0;
    } else {
      cout << m * n - 1 << '\n';
    }
  }
  return 0;
}
