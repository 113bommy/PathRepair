#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
long long n, m, k;
long long cal(long long x) {
  if (mp.find(x) != mp.end()) return mp[x];
  set<long long> s;
  for (long long i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      if (i >= k && (x / i) >= 2) {
        if ((x / i) % 2 == 0)
          s.insert(0);
        else
          s.insert(cal(i));
      }
      if ((x / i) >= k && (i) >= 2) {
        if (i % 2 == 0)
          s.insert(0);
        else
          s.insert(cal(x / i));
      }
    }
  long long r = 0;
  while (s.find(r) != s.end()) ++r;
  mp[x] = r;
  return r;
}
int main() {
  cin >> n >> m >> k;
  mp.clear();
  if (n % 2 == 0)
    printf("Marsel\n");
  else {
    long long x = cal(m);
    if (x)
      printf("Timur\n");
    else
      printf("Marsel\n");
  }
  return 0;
}
