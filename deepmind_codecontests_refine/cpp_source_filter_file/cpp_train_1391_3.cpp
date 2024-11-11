#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string a, b;
int pre[N], suff[N];
vector<int> occ[300];
int main() {
  cin >> a >> b;
  int match = 0;
  int n = (int)a.size(), m = (int)b.size();
  for (int i = 0; i < m; i++) occ[b[i]].push_back(i);
  for (int i = 0; i < n; i++) {
    if (i) pre[i] = pre[i - 1];
    if (match != m && a[i] == b[match]) {
      pre[i]++;
      match++;
    }
  }
  match = 0;
  reverse(((a).begin()), ((a).end())), reverse(((b).begin()), ((b).end()));
  for (int i = 0; i < n; i++) {
    if (i) suff[(n - 1) - i] = suff[(n - 1) - i + 1];
    if (match != m && a[i] == b[match]) {
      suff[(n - 1) - i]++;
      match++;
    }
  }
  reverse(((a).begin()), ((a).end()));
  for (int i = 0; i < n; i++) {
    int idx = upper_bound(((occ[a[i]]).begin()), ((occ[a[i]]).end()), pre[i]) -
              occ[a[i]].begin() - 1;
    if (idx < 0 || 1 + occ[a[i]][idx] + suff[i + 1] < m) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
