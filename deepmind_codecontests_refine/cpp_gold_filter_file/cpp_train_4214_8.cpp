#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  if (x == 0) {
    cout << "YES\n1\n2\n2\n3\n";
  } else if (x == 1) {
    int ip1;
    cin >> ip1;
    cout << "YES"
         << "\n"
         << 2 * ip1 << "\n"
         << 2 * ip1 << "\n"
         << 3 * ip1 << "\n";
  } else if (x == 2) {
    int ip1, ip2, ip11, ip22;
    cin >> ip1 >> ip2;
    ip11 = min(ip1, ip2);
    ip22 = max(ip1, ip2);
    if (4 * ip11 - ip22 > 0) {
      cout << "YES\n" << 4 * ip11 - ip22 << "\n" << 3 * ip11 << "\n";
    } else if (3 * ip11 == ip22) {
      cout << "YES\n" << ip11 * 2 << "\n" << 2 * ip11 << "\n";
    } else if ((ip11 + ip22) % 4 == 0 && (ip11 + ip22) / 4 >= ip11 &&
               3 * ((ip11 + ip22) / 4) >= ip22) {
      cout << "YES\n"
           << (ip11 + ip22) / 4 << "\n"
           << 3 * ((ip11 + ip22) / 4) << "\n";
    } else if (ip22 % 3 == 0) {
      int x1 = ip22 / 3;
      int x2 = 4 * x1 - ip11;
      if (x2 > 0 && x2 < ip22) {
        cout << "YES\n" << x1 << "\n" << x2 << "\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  } else if (x == 3) {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> v;
    v.push_back(x1);
    v.push_back(x2);
    v.push_back(x3);
    sort(v.begin(), v.end());
    if (v[0] * 3 == v[2]) {
      cout << "YES\n" << 4 * v[0] - v[1] << "\n";
    } else if (v[1] + v[2] == 4 * v[0]) {
      cout << "YES\n" << 3 * v[0] << "\n";
    } else if ((4 * v[2]) % 3 == 0 && (v[0] + v[1] == (4 * v[2]) / 3)) {
      cout << "YES\n" << v[2] / 3 << "\n";
    } else {
      cout << "NO\n";
    }
  } else {
    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    vector<int> v;
    v.push_back(x1);
    v.push_back(x2);
    v.push_back(x3);
    v.push_back(x4);
    sort(v.begin(), v.end());
    float val = v[3] - v[0] / 1.0;
    if (val == (v[2] + v[1]) / 2.0 &&
        (v[0] + v[1] + v[2] + v[3]) / 4.0 == val) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
