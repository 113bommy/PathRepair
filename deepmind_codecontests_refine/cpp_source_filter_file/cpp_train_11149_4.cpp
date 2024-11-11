#include <bits/stdc++.h>
using namespace std;
unordered_map<int, long long> m;
int n;
long long getvv(int i) {
  if (m.count(i) > 0) return m[i];
  cout << "? " << (i + 1) << endl;
  cout.flush();
  long long a;
  cin >> a;
  return m[i] = a;
}
long long getv(int i) { return (getvv(i) - getvv((i + n / 2) % n)); }
void ans(long long a) {
  cout << "! " << (1 + a) << endl;
  cout.flush();
  exit(0);
}
int main() {
  cin >> n;
  long long l = 0, u = n / 2;
  int type = 0;
  if (getv(0) == 0) {
    ans(0);
  }
  if (getv(0) > 0) {
    type = 1;
  }
  while (l <= u) {
    long long m = (l + u) / 2;
    if (getv(m) == 0) {
      ans(m);
    } else if (type ^ (getv(m) < 0)) {
      l = m + 1;
    } else {
      u = m - 1;
    }
  }
  ans(-1);
  return 0;
}
