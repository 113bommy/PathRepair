#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < int(v.size()); ++i) {
    in >> v[i];
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (int i = 0; i < int(v.size()); ++i) {
    out << v[i] << " ";
  }
  return out;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> kv;
  for (int i = 0; i * i <= 2000; ++i) kv.push_back(i * i);
  for (int x = -a + 1; x < a; ++x) {
    int y = a * a - x * x;
    bool f = true;
    ;
    for (int i = 0; i < int(kv.size()); ++i) {
      if (kv[i] == y) {
        f = false;
        break;
      }
    }
    if (f) continue;
    y = sqrt(y);
    int g = gcd(x, y);
    x /= g;
    y /= g;
    int c = sqrt(x * x + y * y);
    x *= g;
    if (b % c != 0) continue;
    int y1 = y * g;
    int x1 = x;
    int x2 = -y * b / c;
    int y2 = x / g * b / c;
    if (x1 == x2 || y1 == y2 || x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0)
      continue;
    cout << "YES\n0 0" << endl;
    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
