#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int r = exgcd(b, a % b, x, y);
  int t = y;
  y = x - a / b * y;
  x = t;
  return r;
}
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }
inline int abs(int a) { return a > 0 ? a : -a; }
bool leitu(int a, int &x, int b, int &y, int c) {
  int s, t;
  int GCD = exgcd(a, b, s, t);
  if (abs(c) % GCD) return false;
  int s0 = (-s) * c / GCD;
  int t0 = t * c / GCD;
  int B = b / GCD;
  int A = a / GCD;
  if (s0 >= 0 && t0 >= 0) {
    while (s0 - B >= 0 && t0 - A >= 0) {
      s0 -= B;
      t0 -= A;
    }
  } else {
    while (!(s0 >= 0 && t0 >= 0)) {
      s0 += B;
      t0 += A;
    }
  }
  x = s0;
  y = t0;
  return true;
}
int DAC_array_gcd(int a[], int s, int e) {
  if (s == e) return a[s];
  int mid = (s + e) / 2;
  int l = DAC_array_gcd(a, s, mid);
  int r = DAC_array_gcd(a, mid + 1, e);
  return gcd(l, r);
}
const int maxn = (int)1e3 + 10;
std::pair<int, int> d[maxn];
int s, n;
void xQsort(int low, int high) {
  if (low >= high) return;
  int first = low;
  int last = high;
  std::pair<int, int> key = d[first];
  while (first < last) {
    while (first < last && d[last].first >= key.first) last--;
    d[first] = d[last];
    while (first < last && d[first].first <= key.first) first++;
    d[last] = d[first];
  }
  d[first] = key;
  xQsort(low, first - 1);
  xQsort(first + 1, high);
}
int xBsearch(int low, int high, int x) {
  if (high - low <= 1) {
    if (x <= d[low].first)
      return -1;
    else if (d[high].first < x)
      return high;
    else
      return low;
  }
  int mid = (low + high) / 2;
  if (x <= d[mid].first)
    return xBsearch(low, mid - 1, x);
  else
    return xBsearch(mid + 1, high, x);
}
int main() {
  int x, y;
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    d[i].first = x;
    d[i].second = y;
  }
  xQsort(0, n - 1);
  int l = 0, r;
  bool flag = true;
  while (l < n) {
    r = xBsearch(l, n - 1, s);
    if (r == -1) {
      flag = false;
      break;
    }
    for (int i = l; i <= r; i++) s += d[i].second;
    l = r + 1;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
