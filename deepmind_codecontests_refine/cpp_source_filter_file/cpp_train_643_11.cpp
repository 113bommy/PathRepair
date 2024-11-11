#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sx, sy;
  long long a = 0, b = 0, c = 0, d = 0;
  cin >> n >> sx >> sy;
  pair<long long, long long> pos[n];
  for (int i = 0; i < n; i++) {
    cin >> pos[i].first >> pos[i].second;
    if (pos[i].first >= 0 && pos[i].second > sy) a += a;
    if (pos[i].first > sx && pos[i].second >= 0) b += b;
    if (pos[i].first >= 0 && pos[i].second < sy) c += c;
    if (pos[i].first < sx && pos[i].second >= 0) d += d;
  }
  if (a >= b && a >= c && a >= d) {
    cout << a << "\n";
    cout << sx << " " << sy + 1 << "\n";
  } else if (b >= a && b >= c && b >= d) {
    cout << b << "\n";
    cout << sx + 1 << " " << sy << "\n";
  } else if (c >= a && c >= b && c >= d) {
    cout << c << "\n";
    cout << sx << " " << sy - 1 << "\n";
  } else {
    cout << d << "\n";
    cout << sx - 1 << " " << sy << "\n";
  }
}
