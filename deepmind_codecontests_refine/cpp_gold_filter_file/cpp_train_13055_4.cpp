#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 100;
const long long maxM = 1e3 + 100;
const long long mod = 1e9 + 7;
const long long hmod = 1e16 + 7;
const long double PI = 3.141592653;
const long double eps = 1e-8;
const long long D = 1379;
const long long INF = 1e18 + 20;
const long long Inf = 1e9 + 140;
const long long SQ = 320;
const long long lg = 30;
void NO() {
  cout << "-1" << endl;
  exit(0);
}
void YES() {
  cout << "YES" << endl;
  exit(0);
}
long long n, ans, a[maxN], cop[5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cop[a[i]]++;
  }
  while (cop[2] && cop[1]) {
    cop[2]--;
    cop[1]--;
    cop[3]++;
    ans++;
  }
  if (cop[1]) {
    while (cop[1] >= 3) {
      cop[1] -= 3;
      cop[3]++;
      ans += 2;
    }
    if (cop[1] == 2) {
      if (cop[3] >= 2) {
        cop[3] -= 2;
        cop[1] -= 2;
        cop[4] += 2;
        ans += 2;
      } else if (cop[4]) {
        cop[4]--;
        cop[1] -= 2;
        cop[3] += 2;
        ans += 2;
      } else
        NO();
    }
    if (cop[1] == 1) {
      if (cop[3]) {
        cop[3]--;
        cop[1]--;
        cop[4]++;
        ans++;
      } else if (cop[4] >= 2) {
        cop[4] -= 2;
        cop[1]--;
        cop[3] += 2;
        ans += 2;
      } else
        NO();
    }
  } else if (cop[2]) {
    while (cop[2] >= 3) {
      cop[2] -= 3;
      cop[3] += 2;
      ans += 2;
    }
    if (cop[2] == 2) {
      cop[2] -= 2;
      cop[4]++;
      ans += 2;
    }
    if (cop[2] == 1) {
      if (cop[4]) {
        cop[4]--;
        cop[2]--;
        cop[3] += 2;
        ans++;
      } else if (cop[3] >= 2) {
        cop[2]--;
        cop[3] -= 2;
        cop[4] += 2;
        ans += 2;
      } else
        NO();
    }
  }
  cout << ans << endl;
}
