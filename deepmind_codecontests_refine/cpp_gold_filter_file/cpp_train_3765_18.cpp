#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
const int DEBUG = 0;
mt19937 gen(
    (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
#pragma comment(linker, "/STACK:16777216")
struct mhash {
  unsigned long long h1, h2;
  mhash() { h1 = h2 = 0; }
  mhash(unsigned long long a, unsigned long long b) {
    h1 = a;
    h2 = b;
  }
};
bool operator==(const mhash& a, const mhash& b) {
  return a.h1 == b.h1 && a.h2 == b.h2;
}
mhash operator+(const mhash& a, const mhash& b) {
  return mhash(a.h1 ^ b.h1, a.h2 ^ b.h2);
}
const int N = (int)3e5 + 100;
mhash need[N];
mhash have[N];
mhash to[N];
int a[N];
int n;
int count(int i) {
  int j = i + 1;
  int len = 1;
  int cnt = 1;
  while (j <= n && a[j] != 1) {
    len = max(len, a[j]);
    if (j - len + 1 >= 1 && need[len] == have[j] + have[j - len]) {
      cnt++;
    }
    ++j;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(cout.fixed);
  cout.precision(12);
  auto START_TIME = chrono::high_resolution_clock::now();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    to[i] = mhash(gen(), gen());
    need[i] = to[i] + need[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = 0;
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++) {
      have[i] = have[i - 1] + to[a[i]];
    }
    for (int i = 1; i <= n; i++)
      if (a[i] == 1) res += count(i) - t;
    reverse(a, a + n + 2);
  }
  cout << res;
  return 0;
}
