#include <bits/stdc++.h>
using namespace std;
int n, v, q, k, gg, a[500000], d[3000100];
bool was[3000100], waas[3000100], waaas[3000100];
vector<int> vec;
void pr(int x) {
  for (int j = 0; vec[j] * vec[j] <= x; j++)
    while (x % vec[j] == 0) {
      x /= vec[j];
      if (!waaas[vec[j]]) {
        waaas[vec[j]] = true;
        for (int i = vec[j]; i <= 3000000; i += vec[j]) was[i] = true;
      }
    }
  if (x > 1 && !waaas[x]) {
    waaas[x] = true;
    for (int i = x; i <= 3000000; i += x) was[i] = true;
  }
}
int main() {
  cin >> n;
  for (int i = 2; i * i <= 3000000; i++)
    if (!waas[i])
      for (int j = i * i; j <= 3000000; j += i) waas[j] = true;
  for (int i = 2; i <= 3000000; i++)
    if (!waas[i]) vec.push_back(i);
  for (int i = 2; i <= 3000000; i++) d[i] = i + 1;
  gg = (int)(1e9 + 7);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    k = max(2, a[i]);
    k = min(k, gg);
    v = k;
    while (was[v]) {
      v = d[v];
    }
    if (v > a[i]) gg = 2;
    pr(v);
    cout << v << ' ';
    while (k != v) {
      q = k;
      k = d[k];
      d[q] = v;
    }
  }
  return 0;
}
