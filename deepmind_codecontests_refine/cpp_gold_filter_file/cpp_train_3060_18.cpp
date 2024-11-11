#include <bits/stdc++.h>
using namespace std;
int n;
long long totalTime, L;
vector<long long> pos;
long long x[1000001];
long long check(int upper) {
  if (pos[0] > upper) return -1;
  long long lef = 0, rig = pos.size(), mid;
  while (rig - lef > 1) {
    mid = (rig + lef) / 2;
    if (pos[mid] <= upper)
      lef = mid;
    else
      rig = mid;
  }
  return lef + 1;
}
int MAIN() {
  while (cin >> n >> L >> totalTime) {
    double ans = 0;
    totalTime *= 2;
    for (int i = 0; i < n; i++) {
      long long p;
      cin >> p;
      x[i] = p;
      pos.push_back(p - L);
      pos.push_back(p);
      pos.push_back(p + L);
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; i++) {
      long long d = totalTime % L;
      ans += (n - 1) * (totalTime / L) * 0.25;
      ans += 0.125 * (check(x[i] + d) - check(x[i] - d - 1) - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
