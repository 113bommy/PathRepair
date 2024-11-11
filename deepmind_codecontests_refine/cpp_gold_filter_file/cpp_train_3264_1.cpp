#include <bits/stdc++.h>
using namespace std;
int find_max(int a[], int l, int r) {
  if (l == r) return l;
  int m = (l + r) / 2;
  int f = find_max(a, l, m);
  int s = find_max(a, m + 1, r);
  if (a[f] > a[s]) return f;
  return s;
}
int main() {
  int n, m;
  cin >> n >> m;
  int m1[m], m2[m];
  for (int i = 0; i < m; i++) {
    cin >> m1[i];
    m2[i] = m1[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = find_max(m2, 0, m - 1);
    ans += m2[j];
    m2[j] -= 1;
  }
  cout << ans << " ";
  sort(m1, m1 + m);
  int done = 0;
  ans = 0;
  int i = 0;
  while (done < n) {
    if (m1[i] == 0) i += 1;
    ans += m1[i];
    m1[i] -= 1;
    done += 1;
  }
  cout << ans;
  return 0;
}
