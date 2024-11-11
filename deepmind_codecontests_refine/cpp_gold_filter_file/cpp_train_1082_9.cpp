#include <bits/stdc++.h>
using namespace std;
long long int h[200001], p[200001];
long long int n, m;
bool func(long long int t) {
  long long int counter = 0;
  for (long long int i = 0; i < n; i++) {
    if (counter >= m) {
      break;
    }
    if (p[counter] <= h[i]) {
      long long int orig = counter;
      if (h[i] - p[orig] > t) {
        return false;
      }
      counter++;
      while (counter < m && (t - h[i] + p[orig] + p[orig] >= p[counter] ||
                             p[counter] - p[orig] + p[counter] - h[i] <= t)) {
        counter++;
      }
    } else {
      while (counter < m && t + h[i] >= p[counter]) {
        counter++;
      }
    }
  }
  return (counter >= m);
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  long long int l = 0, r = 20000000000;
  while (l < r) {
    bool res = func((l + r) / 2);
    if (!res) {
      l = (l + r) / 2 + 1;
    } else {
      r = (l + r) / 2;
    }
  }
  cout << l << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
