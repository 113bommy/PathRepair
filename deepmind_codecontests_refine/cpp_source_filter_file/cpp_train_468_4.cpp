#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int dpl[N];
int dpr[N];
int a[N];
int Find1(int lo, int hi, int key) {
  int tmp = hi;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (dpr[mid] > key)
      lo = mid + 1;
    else
      hi = mid;
  }
  if (dpr[hi] > key) return 0;
  return tmp - lo + 1;
}
int Find2(int lo, int hi, int key) {
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (dpl[mid] > key)
      hi = mid - 1;
    else
      lo = mid;
  }
  if (dpl[0] > key) return 0;
  return lo;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b, T;
  cin >> n >> a >> b >> T;
  string s;
  cin >> s;
  dpl[0] = 1 + (s[0] == 'h' ? 0 : b);
  for (int i = 1; i < n; i++) {
    if (s[i] == 'h') {
      dpl[i] = dpl[i - 1] + a + 1;
    } else {
      dpl[i] = dpl[i - 1] + a + b + 1;
    }
  }
  dpr[n - 1] = a + 1 + (s[n - 1] == 'h' ? 0 : b) + dpl[0];
  for (int i = n - 2; i >= 0; i--) {
    dpr[i] = dpr[i + 1] + a + 1 + (s[i] == 'h' ? 0 : b);
  }
  int sc = 0;
  for (int i = 0; i < n; i++) {
    if (dpl[i] <= T) {
      sc = max(i + 1, sc);
      int val = T - i * a - dpl[i];
      int sc1 = Find1(i + 1, n - 1, val) + i + 1;
      sc = max(sc, sc1);
    }
    if (dpr[i] <= T) {
      sc = max(n - i + 1, sc);
      int val = T - (n - i) * a - dpr[i];
      int sc2 = Find2(1, i - 1, val) + (n - i + 1);
      sc = max(sc, sc2);
    }
  }
  cout << min(sc, n) << endl;
  return 0;
}
