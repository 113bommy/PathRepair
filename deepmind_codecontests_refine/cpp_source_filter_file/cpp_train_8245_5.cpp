#include <bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long b);
long long pwr(long long a, long long b, long long m);
int baap[200002];
int find(int i);
bool Union(int x, int y);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  set<long long> s;
  long long x = 0;
  map<long long, long long> mp;
  for (long long i = 0; x < 1e9 + 2; i++) {
    x = i * i + i;
    x /= 2;
    s.insert(x);
    mp[x] = i;
  }
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long xxx = abs(a - b);
    long long l = *s.lower_bound(xxx);
    long long diff = l - xxx;
    if (diff % 2 == 0) {
      cout << mp[l];
    } else {
      long long xx = mp[l] + 1;
      xx *= xx;
      xx += mp[l] + 1;
      xx /= 2;
      diff = xx - xxx;
      if (diff % 2 == 0)
        cout << mp[xx];
      else
        cout << mp[xx] + 1;
    }
    cout << endl;
  }
}
long long pwr(long long a, long long b) {
  if (b == 0) return 1;
  long long c = pwr(a, b / 2);
  c = c * c;
  if (b % 2) return c * a;
  return c;
}
long long pwr(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long c = pwr(a, b / 2, m) % m;
  c = (c * c) % m;
  if (b % 2) return (c * a % m) % m;
  return c;
}
int find(int i) {
  if (baap[i] != i) baap[i] = find(baap[i]);
  return baap[i];
}
bool Union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  baap[x] = y;
  return true;
}
