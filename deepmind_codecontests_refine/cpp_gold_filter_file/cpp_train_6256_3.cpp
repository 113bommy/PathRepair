#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int drvo[1000005];
void build(int i, int j, int node) {
  if (i == j) {
    drvo[node] = a[i];
    return;
  }
  int mid = i + (j - i) / 2;
  build(i, mid, 2 * node + 1);
  build(mid + 1, j, 2 * node + 2);
  drvo[node] = min(drvo[2 * node + 1], drvo[2 * node + 2]);
}
int get(int i, int j, int l, int r, int node) {
  if (i > r || j < l) {
    return 100000000000;
  }
  if (l <= i && r >= j) {
    return drvo[node];
  }
  int mid = i + (j - i) / 2;
  return min(get(i, mid, l, r, 2 * node + 1),
             get(mid + 1, j, l, r, 2 * node + 2));
}
vector<int> g[300005];
int org[200005];
map<int, int> compress;
vector<int> v;
int levo[200005];
int desno[2000005];
int main() {
  int n, q, br = 0, cnt = 0;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == q) {
      br++;
    }
  }
  if (br == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = q;
        br++;
        break;
      }
    }
  }
  if (br == 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = max(1, max(a[i - 1], a[i + 1]));
    }
  }
  for (int i = 0; i < n; i++) {
    org[i] = a[i];
  }
  build(0, n - 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    levo[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    desno[a[i]] = i;
  }
  for (int i = 1; i <= q; i++) {
    int l = levo[i], r = desno[i];
    int mini = get(0, n - 1, l, r, 0);
    if (mini < a[l]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << org[i] << " ";
  }
  cout << endl;
}
