#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const unsigned long long N = 1e6 + 5;
unsigned long long p[N], n, c[N], sum, h[N];
map<unsigned long long, unsigned long long> us;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (unsigned long long i = 1; i < N; i++) p[i] = i;
  for (unsigned long long i = 2; i < N; i++) {
    if (p[i] != i) continue;
    for (unsigned long long j = i; j < N; j += i) {
      p[j] = min(p[j], i);
    }
    c[i] = rnd();
  }
  for (unsigned long long i = 1; i <= n; i++) {
    unsigned long long x = i;
    while (x > 1) {
      h[i] ^= c[p[x]];
      x /= p[x];
    }
    h[i] ^= h[i - 1];
    sum ^= h[i];
  }
  if (sum == 0) {
    cout << n << endl;
    for (unsigned long long i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
    return 0;
  } else {
    for (unsigned long long i = 1; i <= n; i++) {
      if ((sum ^ h[i]) == 0) {
        cout << n - 1 << endl;
        for (unsigned long long j = 1; j <= n; j++) {
          if (j == i) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
    }
    for (unsigned long long i = 1; i <= n; i++) {
      unsigned long long v = (h[i] ^ sum);
      if (us.count(v)) {
        cout << n - 2 << endl;
        for (unsigned long long j = 1; j <= n; j++) {
          if (j == i || j == us[v]) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
      us[h[i]] = i;
    }
    cout << n - 3 << endl;
    for (unsigned long long i = 1; i <= n; i++) {
      if (i == 2 || i == n || i == (n - 1) / 2) continue;
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
}
