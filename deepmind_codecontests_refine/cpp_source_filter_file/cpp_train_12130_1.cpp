#include <bits/stdc++.h>
using namespace std;
int max_min(int a[][2], int k, int i, int j) {
  int mid = i + (j - i) / 2;
  if (i > j) return -1;
  if (i == j) {
    if (a[i][0] < k)
      return i;
    else
      return -1;
  }
  if (a[mid][0] >= k) {
    return max(-1, max_min(a, k, i, mid - 1));
  } else
    return max(mid, max_min(a, k, mid + 1, j));
}
int main() {
  set<pair<int, int> > m;
  int i, j, k, n, ans;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j >> k;
    m.insert(make_pair(j, k));
  }
  set<pair<int, int> >::iterator it = m.begin();
  int a[n + 2][2], blast[n + 2];
  i = 1;
  while (it != m.end()) {
    a[i][0] = (*it).first;
    a[i][1] = (*it).second;
    i++;
    it++;
  }
  blast[1] = 0;
  i = 2;
  while (i <= n) {
    j = max_min(a, a[i][0] - a[i][1], 1, i);
    if (j != -1)
      blast[i] = i - j - 1 + blast[j];
    else
      blast[i] = 0;
    i++;
  }
  for (i = 1, ans = 999999; i <= n; i++) {
    if (blast[i] + n - i < ans) ans = blast[i] + n - i;
  }
  cout << ans;
  return 0;
}
