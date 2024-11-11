#include <bits/stdc++.h>
using namespace std;
int conversion(string p) {
  int o;
  o = atoi(p.c_str());
  return o;
}
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
string toStringLong(long long h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
int main() {
  int m;
  cin >> m;
  vector<int> ad;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    ad.push_back(a);
  }
  int x, y;
  cin >> x >> y;
  int minimo = 0;
  int maximo = 0, ok = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < i; j++) {
      minimo += ad[j];
    }
    for (int j = i; j < m; j++) {
      maximo += ad[j];
    }
    if (minimo >= x & minimo <= y & maximo >= x & maximo <= y) {
      ok = ad[i];
      break;
    }
    minimo = 0;
    maximo = 0;
  }
  cout << ok << '\n';
}
