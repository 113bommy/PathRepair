#include <bits/stdc++.h>
using namespace std;
vector<long long> v[30004];
void pre() {
  for (long long i = 1; i <= 10000; i++)
    for (long long j = i; j <= 20000; j += i) v[i].push_back(j);
}
int32_t main() {
  long long t;
  cin >> t;
  pre();
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long mini = 1e12;
    long long xx, yy, zz;
    for (long long i = 1; i <= 10000; i++) {
      for (auto x : v[i]) {
        for (auto y : v[x]) {
          if (mini > abs(i - a) + abs(x - b) + abs(y - c)) {
            mini = abs(i - a) + abs(x - b) + abs(y - c);
            xx = i;
            yy = x;
            zz = y;
          }
        }
      }
    }
    cout << mini << endl;
    cout << xx << " " << yy << " " << zz << endl;
  }
  return 0;
}
