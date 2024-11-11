#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b, long long mod) {
  stack<int> k;
  int j = 2048;
  int l = 1;
  int an = 1;
  while (b) {
    if (b >= j) {
      k.push(j);
      b -= j;
    }
    j /= 2;
  }
  while (!k.empty()) {
    if (k.top() == l) {
      an = (an * a) % mod;
      k.pop();
    }
    a = (a * a) % mod;
    l *= 2;
  }
  return an;
}
long long an = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x, y;
  cin >> n >> x >> y;
  int xx[n];
  for (int i = 0; i < n; ++i) {
    cin >> xx[i];
  }
  for (int i = 0; i < n; ++i) {
    int f = 1;
    for (int j = i - 1, s = 0; j < n && s < x; ++s, --j) {
      if (xx[j] < xx[i]) {
        f = 0;
      }
    }
    for (int j = i + 1, s = 0; j < n && s < y; ++s, ++j) {
      if (xx[j] < xx[i]) {
        f = 0;
      }
    }
    if (f) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
