#include <bits/stdc++.h>
using namespace std;
ifstream in("file.in");
ofstream out("file.out");
struct comp {
  bool operator()(long long a, long long b) { return a > b; }
};
long long n, first, t, r, a[100005], p[45], q[45], pos;
bool pw(long long first) {
  long long q = 1;
  while (!(first & q)) q *= 2;
  if (first - q) return 0;
  return 1;
}
int lg2(long long first) {
  long long q = 1, c = 0;
  while (first) {
    if (first & q) first -= q;
    q *= 2;
    c++;
  }
  return c - 1;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (pw(a[i]))
      p[lg2(a[i])]++;
    else
      p[lg2(a[i])]++;
  }
  for (int i = 1; i <= p[0]; i++) {
    t = i;
    r = 0;
    for (int j = 0; j <= 40; j++) {
      if (p[j] >= t)
        r += p[j] - t + q[j];
      else {
        r -= t - p[j];
        if (r < 0) r = 0;
        r += q[j];
        t = p[j];
      }
    }
    if (!r) cout << i << ' ', pos = 1;
  }
  if (!pos) cout << -1;
}
