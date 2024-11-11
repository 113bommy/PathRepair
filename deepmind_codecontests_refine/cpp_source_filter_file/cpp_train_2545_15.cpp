#include <bits/stdc++.h>
using namespace std;
void bahut_tezz() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void jai_bajrangbali() {
  long long c, d, e, n, k, x, y, z, cnt = 0, res = 0, mx = 1;
  long long sum = 0;
  bool ash = false;
  long long x1, y1, x2, y2;
  string s;
  cin >> x1 >> y1 >> x2 >> y2;
  if ((x2 - x1) == (y2 - y1)) {
    cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
    return;
  }
  vector<long long> v;
  v.push_back(x1);
  v.push_back(y1);
  v.push_back(x2);
  v.push_back(y2);
  for (long long i = 0; i < 4; i++) {
    for (long long j = i + 1; j < 4; j++) {
      if (v[i] == v[j]) {
        ash = 1;
        break;
      }
    }
  }
  if (ash) {
    x = max(abs(x2 - x1), abs(y2 - y1));
    if (x1 == x2) {
      cout << x2 + x << " " << y2 << " " << x1 + x << " " << y1 << "\n";
    } else if (y1 == y2) {
      cout << x1 << " " << y1 + x << " " << x2 << " " << y2 + x << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
}
int main() {
  bahut_tezz();
  long long t;
  t = 1;
  while (t--) jai_bajrangbali();
  return 0;
}
