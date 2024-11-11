#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  for (const auto& x : v) {
    if (!first) {
      os << " ";
    }
    first = false;
    os << x;
  }
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& elem : v) {
    is >> elem;
  }
  return is;
}
long long pw(long long x, int n) {
  if (n == 1) {
    return x;
  }
  if (n % 2 == 0) {
    return pw((x * x) % 1000000007, n / 2);
  }
  return (pw(x, n - 1) * x) % 1000000007;
}
long long dv(long long a, long long b) {
  return (a * pw(b, 1000000007 - 2)) % 1000000007;
}
vector<long long> f;
void set_f(int n) {
  f.resize(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * i) % 1000000007;
  }
}
long long c_n_k(int n, int k) { return dv(dv(f[n], f[k]), f[n - k]); }
int get_min(map<int, int>& m) { return m.begin()->first; }
int get_min2(map<int, int>& m) {
  auto it = m.begin();
  it++;
  return it->first;
}
int get_min(set<int>& m) { return *m.begin(); }
int get_max(map<int, int>& m) {
  auto it = m.end();
  it--;
  return it->first;
}
int get_max2(map<int, int>& m) {
  auto it = m.end();
  it--;
  it--;
  return it->first;
}
int get_max(set<int>& m) {
  auto it = m.end();
  it--;
  return *it;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string a = s + s;
  bool f = true;
  bool f2 = true;
  for (int i = 0; i < n; i++) {
    if (a[i + 1] != a[i] && a[i + 1] != a[i + 2]) {
      f = false;
    }
    if (a[i] == a[i + 1]) {
      f2 = false;
    }
  }
  if (f) {
    cout << s;
    return;
  }
  if (f2) {
    if (k % 2 == 0) {
      cout << s;
    } else {
      for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
          cout << 'B';
        } else {
          cout << 'W';
        }
      }
    }
    return;
  }
  a = s;
  int offset = 0;
  if (a[0] != a[n - 1]) {
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        a = s.substr(i + 1, n - i - 1) + s.substr(0, i + 1);
        offset = i + 1;
        break;
      }
    }
  }
  a = a + a + a;
  int i = 0;
  while (i < n) {
    while (i < n && a[i] == a[i + 1]) {
      i++;
    }
    if (a[i + 1] == a[i + 2]) {
      i++;
    } else {
      int j = i + 1;
      while (a[j] != a[j + 1]) {
        j++;
      }
      int l = (j - i) / 2;
      if (k >= l) {
        for (int ii = i + 1; ii <= i + l; ii++) {
          a[ii] = a[i];
        }
        for (int ii = j - l; ii < j; ii++) {
          a[ii] = a[j];
        }
      } else {
        for (int ii = i + 1; ii <= i + k; ii++) {
          a[ii] = a[i];
        }
        for (int ii = j - k; ii < j; ii++) {
          a[ii] = a[j];
        }
        for (int ii = i + k + 1; ii < j - k; ii++) {
          if (k % 2) {
            if (a[ii] == 'W') {
              a[ii] = 'B';
            } else {
              a[ii] = 'W';
            }
          }
        }
      }
      i = j;
    }
  }
  for (int i = n - offset; i < n; i++) {
    cout << a[i];
  }
  for (int i = 0; i < n - offset; i++) {
    cout << a[i];
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  if (0) {
    int tests;
    cin >> tests;
    while (tests--) {
      solve();
      cout << endl;
    }
  } else {
    solve();
    cout << endl;
  }
  return 0;
}
