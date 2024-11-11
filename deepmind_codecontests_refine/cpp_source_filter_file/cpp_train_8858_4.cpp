#include <bits/stdc++.h>
using namespace std;
int n, cnt[2000], x[2000], y[2000], tot;
vector<int> v0, v1;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a]++, cnt[b]++;
  }
  bool apr = 0;
  for (int i = 1; i <= n; i++) {
    if (i == n) break;
    if (cnt[i] == 0) v0.push_back(i);
    if (cnt[i] != 0) v1.push_back(i);
  }
  if (cnt[n] != n - 1) {
    cout << "NO" << endl;
    return 0;
  }
  int i, j = 0, k;
  for (i = 0; i < v1.size(); i++) {
    int u = v1[i];
    if (cnt[u] == 1) continue;
    j += cnt[u] - 2;
    if (j >= v0.size() || v0[j] > u) {
      cout << "NO" << endl;
      return 0;
    }
    j++;
  }
  j = 0;
  for (i = 0; i < v1.size(); i++) {
    int u = v1[i];
    if (cnt[u] == 1) {
      x[++tot] = n, y[tot] = u;
      continue;
    }
    if (cnt[u] == 2) {
      x[++tot] = n, y[tot] = v0[j];
      x[++tot] = v0[j], y[tot] = u;
      j++;
      continue;
    }
    int pre = n;
    k = cnt[u] - 1;
    while (k--) {
      x[++tot] = pre, y[tot] = v1[j++];
      pre = y[tot];
    }
    x[++tot] = pre, y[tot] = u;
  }
  cout << "YES" << endl;
  for (i = 1; i < n; i++) {
    cout << x[i] << ' ' << y[i] << endl;
  }
  return 0;
}
