#include <bits/stdc++.h>
using namespace std;
int t[1010];
long long int f[1010], g[1010];
vector<int> v;
int main() {
  int hf[1010], hg[1010];
  long long int n, i, j, res, tmp, cnt, key;
  cin >> n;
  for (i = 0; i < n; i++) {
    f[i] = 100000000, g[i] = 1000000000, hf[i] = -1;
    hg[i] = -1;
  }
  for (i = 0; i < n; i++) cin >> t[i];
  f[n - 1] = t[n - 1], f[n - 2] = max(t[n - 1], t[n - 2]), g[n - 2] = t[n - 2];
  hf[n - 1] = n - 1, hf[n - 2] = n - 1, hg[n - 2] = n - 2;
  for (i = n - 3; i >= 0; i--) {
    key = 0, cnt = 0, res = 0, tmp = 0;
    for (j = i + 1; j < n; j += 2) key += max(t[j], t[j + 1]);
    if ((n - i) % 2 == 1) key += t[n];
    for (j = i + 2; j < n; j += 2) cnt += max(t[j], t[j + 1]);
    if ((n - i) % 2 == 0) cnt += t[n];
    for (j = i + 2; j < n; j++) {
      if ((j - i) % 2) {
        res += max(t[j - 1], t[j - 2]);
        if (f[i] > res + f[j + 1] + max(t[i], t[j])) hf[i] = j;
        f[i] = min(f[i], res + f[j + 1] + max(t[i], t[j]));
        if (g[i] > tmp + g[j - 1] + max(t[i], t[j])) hg[i] = j;
        g[i] = min(g[i], tmp + g[j - 1] + max(t[i], t[j]));
      }
      if ((j - i) % 2 == 0 && (j - i - 2) > 0) tmp += max(t[j - 1], t[j - 2]);
      if ((j - i) % 2 == 0) {
        if (f[i] > res + g[j - 1] + max(t[i], t[j])) hf[i] = j;
        f[i] = min(f[i], res + g[j - 1] + max(t[i], t[j]));
        if (g[i] > tmp + f[j + 1] + max(t[i], t[j])) hg[i] = j;
        g[i] = min(g[i], tmp + f[j + 1] + max(t[i], t[j]));
      }
    }
    if (f[i] > f[i + 2] + max(t[i], t[i + 1])) hf[i] = i + 1;
    f[i] = min(f[i], f[i + 2] + max(t[i], t[i + 1]));
    if (f[i] > key + t[i]) hf[i] = n;
    f[i] = min(f[i], key + t[i]);
    if (g[i] > cnt + t[i]) hg[i] = n;
    g[i] = min(g[i], cnt + t[i]);
  }
  cout << f[0] << endl;
  for (i = 0; i < n; i++) v.push_back(i);
  if (v[0] + 1 == v[1])
    j = hf[v[0]];
  else
    j = hg[v[0]];
  while (!v.empty()) {
    if (v.size() == 1) {
      cout << v[0] + 1 << endl;
      break;
    }
    if (v.size() == 2) {
      cout << v[0] + 1 << " " << v[1] + 1 << endl;
      break;
    }
    if (v[1] != j && v[2] != j) {
      cout << v[1] + 1 << " " << v[2] + 1 << endl;
      v.erase(v.begin() + 1);
      v.erase(v.begin() + 1);
    }
    if (v.size() > 1 && v[1] == j) {
      cout << v[0] + 1 << " " << v[1] + 1 << endl;
      v.erase(v.begin() + 0);
      v.erase(v.begin() + 0);
      if (v[0] + 1 == v[1])
        j = hf[v[0]];
      else
        j = hg[v[0]];
    }
    if (v.size() > 2 && v[2] == j) {
      cout << v[0] + 1 << " " << v[2] + 1 << endl;
      v.erase(v.begin() + 0);
      v.erase(v.begin() + 1);
      if (v[0] + 1 == v[1])
        j = hf[v[0]];
      else
        j = hg[v[0]];
    }
  }
  return 0;
}
