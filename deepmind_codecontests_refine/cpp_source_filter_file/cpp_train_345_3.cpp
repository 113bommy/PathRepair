#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
using namespace std;
const int DEBUG = 0;
mt19937 gen(
    (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
#pragma comment(linker, "/STACK:67108864")
struct pp {
  int cnt, fuel, len;
};
bool operator<(const pp& a, const pp& b) {
  if (a.len != b.len) return a.len < b.len;
  if (!a.len) return 0;
  return a.fuel > b.fuel;
}
int sz, bad, res1, res2;
long long t[100100];
void take(int t1, int f1, int t2, int f2) {
  t1 += t2;
  t2 -= min(t2, bad);
  int n = sz - t2;
  int pos = upper_bound(t, t + n, f2) - t;
  t1 += pos;
  if (pos) f1 += t[pos - 1];
  if (t1 > res1 || (t1 == res1 && f1 < res2)) {
    res1 = t1;
    res2 = f1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, max_fuel;
  cin >> n >> d >> max_fuel;
  vector<pp> a, b;
  for (int i = 0; i < n; i++) {
    int cnt, fuel, len;
    cin >> cnt >> fuel >> len;
    len = (len >= d);
    if (cnt > 0)
      a.push_back({cnt, fuel, len});
    else
      b.push_back({cnt, fuel, len});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long sum = 0;
  for (int i = 0; i < b.size(); i++)
    if (b[i].len) {
      sum += b[i].fuel;
      t[sz++] = sum;
    } else
      bad++;
  take(0, 0, 0, max_fuel);
  long long free = 0;
  for (int i = 0; i < a.size(); i++) free += a[i].cnt;
  free -= a.size();
  sum = 0;
  for (int i = 0; i < a.size(); i++)
    if (a[i].len && max_fuel >= a[i].fuel) {
      sum += a[i].fuel;
      max_fuel -= a[i].fuel;
      free++;
      take(a.size(), sum, min(free, (long long)b.size()), max_fuel);
    }
  cout << res1 << " " << res2;
  return 0;
}
