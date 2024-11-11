#include <bits/stdc++.h>
using namespace std;
struct CP {
  int q;
  int w;
  bool operator<(const CP &rhs) const { return w > rhs.w; }
};
int n, m;
CP arr[100100];
bool check(long long v) {
  long long t;
  t = v * (v - 1) / 2 + 1;
  if (v % 2 == 0) {
    t += v / 2 - 1;
  }
  return (t <= n);
}
int main(int argc, char *argv[]) {
  long long res;
  int lo, hi, mid;
  cin >> n >> m;
  for (int i = 0; i < m; i += 1) {
    cin >> arr[i].q >> arr[i].w;
  }
  lo = 1;
  hi = m;
  while (lo != hi) {
    mid = lo + (hi - lo + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  res = 0LL;
  sort(arr, arr + m);
  for (int i = 0; i < lo; i += 1) {
    res += arr[i].w;
  }
  cout << res << endl;
  return 0;
}
