#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, dev = 1;
  cin >> n;
  if (n == 1) return cout << 1, 0;
  vector<long long> v1, v2;
  for (i = 1; i * i < n; i++) {
    if (n % i == 0) {
      v1.push_back(n / i);
      v2.push_back(i);
    }
  }
  bool f = 0;
  for (i = 0; i < v1.size(); i++) {
    j = 2;
    while (j * j < v1[i]) {
      if (v1[i] % (j * j) == 0) break;
      j++;
    }
    if (j * j > v1[i]) {
      dev = v1[i];
      f = 1;
      break;
    }
  }
  if (!f) {
    for (i = v2.size() - 1; i >= 0; i--) {
      j = 2;
      while (j * j < v2[i]) {
        if (v2[i] % (j * j) == 0) break;
        j++;
      }
      if (j * j > v2[i]) {
        dev = v2[i];
        break;
      }
    }
  }
  return cout << dev, 0;
}
