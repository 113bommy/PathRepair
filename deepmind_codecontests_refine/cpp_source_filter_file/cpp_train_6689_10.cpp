#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
long long wi(long long s, long long e) {
  if (e & 1)
    return (s & 1) ^ 1;
  else {
    if (2 * s > e)
      return s & 1;
    else if (4 * s > e)
      return 1;
    else
      return wi(s, e / 4);
  }
}
long long lo(long long s, long long e) {
  if (2 * s >= e)
    return 1;
  else
    return wi(s, e / 2);
}
int w[N], l[N];
int n;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long s, e;
    cin >> s >> e;
    w[i] = wi(s, e);
    l[i] = lo(s, e);
  }
  for (long long i = n - 1; i >= 1; i--) {
    int W = w[i], L = l[i];
    w[i] = (W && !w[i + 1]) || (L && w[i + 1]);
    l[i] = (W && !l[i + 1]) || (L && l[i + 1]);
  }
  cout << w[1] << ' ' << l[1] << endl;
}
