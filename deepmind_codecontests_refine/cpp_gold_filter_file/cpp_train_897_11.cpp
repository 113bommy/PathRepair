#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int n;
long long a[N], answ;
vector<pair<long long, int> > g;
long long h[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (i == 1)
      g.push_back({a[i], i});
    else {
      if (a[i] > g.back().first) {
        g.push_back({a[i], i});
      }
    }
  }
  long long mx = 0;
  for (int i = (int)g.size() - 1; i >= 1; i--) {
    long long x = mx + g[i].first - g[i - 1].first;
    int l = g[i - 1].second, r = g[i].second;
    for (int j = r; j > l; j--) {
      if (x == 0) break;
      x--;
      h[j] = 1;
    }
    mx = x;
  }
  h[1] = 1;
  long long H = 0;
  for (int i = 1; i <= n; i++) {
    H += h[i];
    answ += H - a[i] - 1;
  }
  cout << answ << endl;
  return 0;
}
