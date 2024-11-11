#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
double power(double a, long long b) {
  double x = 1;
  for (int i = 0; i < b; i++) {
    x = x * a;
  }
  return x;
}
int main() {
  vector<pair<int, char>> v;
  v.push_back({0, 'A'});
  v.push_back({0, 'B'});
  v.push_back({0, 'C'});
  char x, y, op;
  for (int i = 0; i < 3; i++) {
    cin >> x >> op >> y;
    if (op == '>') {
      for (int j = 0; j < 3; j++) {
        if (v[j].second == x) v[j].first++;
      }
    } else {
      for (int j = 0; j < 3; j++) {
        if (v[j].second == y) v[j].first++;
      }
    }
  }
  sort(v.rbegin(), v.rend());
  if (v[0].first == 2 && v[1].first == 1 && v[2].first == 0) {
    cout << v[2].second << v[1].second << v[0].second << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
