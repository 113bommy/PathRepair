#include <bits/stdc++.h>
using namespace std;
const long long maxA = 1000000, maxN = 300000;
long long t1[maxN * 4], t2[maxN * 4], n, a[maxN], no, su, ko, i, j, s;
void modi(long long v, long long l, long long r, long long g, long long h) {
  if (l == r) {
    t1[v] = h;
    t2[v] = g;
    return;
  }
  long long mid = (l + r) / 2;
  if (g <= mid)
    modi(v * 2, l, mid, g, h);
  else
    modi(v * 2 + 1, mid + 1, r, g, h);
  if (t1[v * 2] < t1[v * 2 + 1]) {
    t1[v] = t1[v * 2];
    t2[v] = t2[v * 2];
  } else {
    t1[v] = t1[v * 2 + 1];
    t2[v] = t2[v * 2 + 1];
  }
}
int main() {
  cin >> n;
  for (i = 0; i < n;
       i++, su += a[i - 1], s += a[i - 1], modi(1, 1, n, i, a[i - 1]))
    cin >> a[i];
  for (i = 0; i < n - 1; i++) {
    if (t1[1] == maxA) break;
    s += su;
    su -= t1[1];
    modi(1, 1, n, t2[1], maxA);
  }
  cout << s;
}
