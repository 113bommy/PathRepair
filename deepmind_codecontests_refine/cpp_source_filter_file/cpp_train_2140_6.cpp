#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m;
int a[MAXN];
int b[MAXN];
int abs(int x) { return x < 0 ? -x : x; }
int find(int i) {
  int l = 0, r = m;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (b[mid] == a[i])
      return 0;
    else if (b[mid] < a[i])
      l = mid;
    else
      r = mid;
  }
  return abs(a[i] - b[l]) < abs(a[i] - b[r]) ? abs(a[i] - b[l])
                                             : abs(a[i] - b[r]);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int r = 0;
  for (int i = 0; i < n; i++) {
    int tmp = find(i);
    if (tmp > r) r = tmp;
  }
  cout << r << endl;
  return 0;
}
