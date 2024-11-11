#include <bits/stdc++.h>
long long int mod = 1e9 + 7;
using namespace std;
long long int power(int a, int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b = b >> 1;
  }
  return ans;
}
long long int factorial(int x) {
  if (x == 0 || x == 1) return 1;
  return (x * factorial(x - 1)) % mod;
}
int main() {
  long long int n, k = 0, i, sum, t, l1, r1, m, x, z, f = 0, w, d;
  cin >> n;
  vector<int> v, v1, p;
  if (n == 1)
    cout << 0;
  else if (n == 2) {
    cout << 1 << endl;
    cout << 2;
  } else if (n == 3) {
    cout << 2 << endl;
    cout << 2 << " " << 3;
  } else {
    v.push_back(2);
    v.push_back(3);
    for (int i = 4; i <= n; i++) {
      z = 0;
      for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
          z = 1;
          break;
        }
      }
      if (z == 0)
        v.push_back(i);
      else
        v1.push_back(i);
    }
    for (int i = 0; i < v1.size(); i++) {
      k = 0;
      for (int j = 0; j < v.size(); j++) {
        if ((v1[i]) % (v[j]) == 0) {
          k++;
        }
      }
      if (k < 2) p.push_back(v1[i]);
    }
    cout << p.size() + v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    for (int i = 0; i < p.size(); i++) {
      cout << p[i] << " ";
    }
  }
}
