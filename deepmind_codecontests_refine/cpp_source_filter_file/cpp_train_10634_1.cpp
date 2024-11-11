#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int n, a[maxn], b[maxn] = {0};
int main() {
  ios::sync_with_stdio(false);
  int i, j, k, max1 = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]]++;
    max1 = max(max1, a[i]);
  }
  long long l, r, min1 = 1e15;
  for (i = 1; i <= max1; i++) {
    vector<int> v;
    for (j = i; j <= max1; j += i) {
      if (!b[j]) continue;
      for (k = 0; k < min(2, b[j]); k++) v.push_back(j);
      if (v.size() >= 2) break;
    }
    if (v.size() >= 2) {
      long long sum = v[0] / i * v[1];
      if (sum < min1) min1 = sum, l = v[0], r = v[1];
    }
  }
  for (i = 1; i <= n; i++) {
    if (a[i] == l) {
      l = i;
      break;
    }
  }
  for (i = 1; i <= n; i++) {
    if (a[i] == r && i != l) {
      r = i;
      break;
    }
  }
  if (l > r) swap(l, r);
  cout << l << " " << r << endl;
}
