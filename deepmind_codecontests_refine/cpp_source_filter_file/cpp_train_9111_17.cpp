#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const double eps = 1e-9;
bool IsPrimeSlow(long long x) {
  if (x <= 1) return false;
  if (x <= 3) return true;
  if (!(x % 2) | !(x % 3)) return false;
  long long s = (long long)(sqrt((double)(x)) + eps);
  for (long long i = 5; i <= s; i += 6)
    if (!(x % i) || !(x % (i + 2))) return false;
  return true;
}
int n, a[N], b, c, o;
set<int> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
    if (a == 1) o++;
  }
  int i = 0;
  n = s.size();
  for (auto x : s) {
    a[i] = x;
    i++;
  }
  if (o > 1) {
    for (int i = 1; i < n; i++) {
      int t = a[0] + a[i];
      if (IsPrimeSlow(t)) {
        c = a[i];
        break;
      }
    }
    if (c) {
      cout << o + 1 << endl;
      cout << c << " ";
    } else {
      cout << o << endl;
    }
    for (int i = 0; i < o; i++) cout << 1 << " ";
  } else {
    for (int i = 0; i < n; i++) {
      b = a[i];
      for (int j = i; j < n; j++) {
        int t = a[i] + a[j];
        if (IsPrimeSlow(t)) {
          c = a[j];
          break;
        }
      }
      if (c) {
        cout << 2 << endl;
        cout << b << " " << c;
        return 0;
      }
    }
    cout << 1 << endl;
    cout << a[0];
  }
}
