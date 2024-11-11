#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v, a;
int main() {
  bool z;
  int t;
  cin >> n;
  for (int i = 1; i <= (int)sqrt((double)n); i++)
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  sort(v.begin(), v.end());
  for (int i = 2; i < n; i++) {
    if ((long long)i * i > n) break;
    if (n % ((long long)i * i) == 0) a.push_back((long long)i * i);
  }
  t = (int)a.size() - 1;
  for (int i = (int)v.size() - 1; i >= 0; i--) {
    z = false;
    while (t > 0) {
      if (a[t] <= v[t]) break;
      t--;
    }
    for (int j = 0; j <= t; j++)
      if (v[i] % a[j] == 0) {
        z = true;
        break;
      }
    if (z == false) {
      cout << v[i] << endl;
      return 0;
    }
  }
  return 0;
}
