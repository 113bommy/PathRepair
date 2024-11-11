#include <bits/stdc++.h>
using namespace std;
bool diff[25];
vector<int> v, v1, v2;
int n, x, y, LOG = 1;
bool check(int l, int r) {
  cout << "? " << r - l + 1 << " ";
  for (int i = l; i <= r; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
  int read;
  cin >> read;
  if (read == 0 || read == x) {
    return 0;
  }
  return 1;
}
int main() {
  cin >> n >> x >> y;
  int z = x ^ y;
  while ((1 << LOG) <= n) {
    LOG++;
  }
  int bit;
  for (int i = 0; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      if ((1 << i) & j) v.push_back(j);
    }
    cout << "? " << v.size() << " ";
    for (auto j : v) {
      cout << j << " ";
    }
    cout << "\n";
    int read;
    cin >> read;
    if (read == z || read == y) {
      diff[i] = 1;
      bit = i;
    }
    v.clear();
  }
  for (int i = 1; i <= n; i++) {
    if ((1 << bit) & i)
      v1.push_back(i);
    else
      v2.push_back(i);
  }
  v.clear();
  if (v1.size() < v2.size()) {
    for (auto i : v1) {
      v.push_back(i);
    }
  } else {
    for (auto i : v2) {
      v.push_back(i);
    }
  }
  int l = 0, r = v.size() - 1;
  while (l != r) {
    int mid = (l + r) / 2;
    if (check(l, mid))
      r = mid;
    else
      l = mid + 1;
  }
  int res1 = v[l];
  int res2 = 0;
  for (int i = 0; i < LOG; i++) {
    if (diff[i]) {
      if (!((1 << i) & res1)) res2 ^= (1 << i);
    } else {
      res2 ^= ((1 << i) & res1);
    }
  }
  cout << "! " << min(res1, res2) << " " << max(res1, res2);
}
