#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, i, j;
  cin >> a >> b >> c >> d;
  if (a > b) {
    if (c == 0 && d == 0 && a == b + 1) {
      cout << "YES" << endl;
      for (i = 0; i < b; i++) {
        cout << 0 << " " << 1 << " ";
      }
      cout << 0;
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (d > c) {
    if (a == 0 && b == 0 && d == c + 1) {
      cout << "YES" << endl;
      for (i = 0; i < c; i++) {
        cout << 2 << " " << 3 << " ";
      }
      cout << 2;
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  long long tmp = b - a;
  long long tmp1 = c - d;
  if (abs(tmp - tmp) > 1) {
    cout << "NO";
    return 0;
  }
  vector<long long> v;
  for (i = 0; i < a; i++) {
    v.push_back(0);
    v.push_back(1);
  }
  b -= a;
  long long diff = min(tmp, tmp1);
  for (i = 0; i < diff; i++) {
    v.push_back(2);
    v.push_back(1);
  }
  b -= diff;
  c -= diff;
  for (i = 0; i < d; i++) {
    v.push_back(2);
    v.push_back(3);
  }
  c -= d;
  if (c < 0) {
    cout << "NO";
    return 0;
  }
  if (c) {
    v.push_back(2);
  }
  cout << "YES" << endl;
  if (b) cout << 1 << " ";
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
}
