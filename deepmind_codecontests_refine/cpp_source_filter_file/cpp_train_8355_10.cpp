#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 2) {
      cout << x << ' ' << y << '\n';
      continue;
    }
    int f = 0;
    int diff = y - x;
    for (int i = 1; i <= y - x; i++) {
      int p = x, cnt = 0;
      while (p < y) {
        p += i;
        cnt++;
        if (p == y && cnt < n) {
          f = 1;
          diff = i;
          break;
        }
      }
      if (f) break;
    }
    vector<int> v;
    int p = x;
    v.push_back(p);
    v.push_back(y);
    while (p + diff < y) {
      p += diff;
      v.push_back(p);
    }
    if (v.size() < n) {
      p = x;
      while (p - diff > 0 && v.size() < n) {
        p -= diff;
        v.push_back(p);
      }
      p = x + diff;
      while (v.size() < n) {
        v.push_back(p);
        p += diff;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << v[i] << ' ';
    }
    puts("");
  }
}
