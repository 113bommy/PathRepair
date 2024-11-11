#include <bits/stdc++.h>
using namespace std;
const int PUT = 34;
long long two[PUT];
long long three[PUT];
unordered_map<long long, int> H;
long long v[100999];
inline long long cmmdc(long long a, long long b) {
  long long r;
  while (r = a % b) {
    a = b;
    b = r;
  }
  return b;
}
int main() {
  ios ::sync_with_stdio(false);
  two[0] = 1;
  three[0] = 1;
  for (register int i = 1; i <= 32; ++i) {
    two[i] = two[i - 1] * 2LL;
    three[i] = three[i - 1] * 3LL;
  }
  int n;
  cin >> n;
  cin >> v[1];
  cin >> v[2];
  long long w = cmmdc(v[1], v[2]);
  for (register int i = 3; i <= n; ++i) {
    cin >> v[i];
    w = cmmdc(w, v[i]);
  }
  for (register int i = 1; i <= n; ++i) {
    long long x = v[i];
    x /= w;
    for (register int i = 30; i >= 0; --i) {
      if (x % two[i] == 0) {
        x /= two[i];
      }
      if (x % three[i] == 0) {
        x /= three[i];
      }
    }
    if (x != 1) {
      cout << "No\n";
      exit(0);
    }
  }
  cout << "Yes\n";
  return 0;
}
