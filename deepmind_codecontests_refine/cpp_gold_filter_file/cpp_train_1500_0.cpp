#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int a[11], b[11];
int main() {
  int n, Minx = 99999, Miny = 99999, Maxx = 0, Maxy = 0;
  long long S = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    Minx = min(Minx, a);
    Maxx = max(Maxx, c);
    Miny = min(Miny, b);
    Maxy = max(Maxy, d);
    S += ((c - a) * (d - b));
  }
  if (Maxx - Minx == Maxy - Miny && (Maxx - Minx) * (Maxy - Miny) == S)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  cin >> n;
}
