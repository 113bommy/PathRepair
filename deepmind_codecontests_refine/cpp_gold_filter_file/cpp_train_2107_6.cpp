#include <bits/stdc++.h>
using namespace std;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 1000000007);
}
long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long t, n, c[300000], ar[300000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i += 1) cin >> ar[i];
    bool bs = 1;
    for (int i = 0; i < n; i += 1)
      if (ar[i] != ar[(i + 1) % n]) bs = 0;
    if (bs) {
      cout << 1 << "\n";
      for (int i = 0; i < n; i += 1) cout << "1 ";
      cout << "\n";
      continue;
    }
    if (n % 2 == 0) {
      cout << 2 << "\n";
      for (int i = 0; i < n; i += 1) cout << i % 2 + 1 << " ";
      cout << "\n";
      continue;
    }
    bool s = 0;
    int ind = 0;
    for (int i = 0; i < n; i += 1) {
      if (ar[i] == ar[(i + 1) % n]) {
        s = 1;
        ind = i;
        break;
      }
    }
    if (s) {
      c[ind] = 1;
      c[(ind + 1) % n] = 1;
      int cl = 1;
      for (int j = ind + 2; j < ind + n; j++) {
        c[j % n] = cl % 2 + 1;
        cl++;
      }
      cout << 2 << "\n";
      for (int i = 0; i < n; i += 1) cout << c[i] << " ";
      cout << "\n";
    } else {
      cout << 3 << "\n";
      for (int i = 0; i < n - 1; i += 1) cout << i % 2 + 1 << " ";
      cout << 3 << "\n";
    }
  }
}
