#include <bits/stdc++.h>
using namespace std;
vector<int> a[30005];
int main() {
  int n, m, p, q, i, j;
  vector<int> v;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &p, &q);
    a[p].push_back(q);
  }
  for (i = 1; i <= n; i++) {
    v.push_back(i);
    j = i - 2;
    while (j >= 0) {
      sort(a[v[j]].begin(), a[v[j]].end());
      if (binary_search(a[v[j]].begin(), a[v[j]].end(), i)) {
        swap(v[j], v[j + 1]);
        j--;
      } else
        break;
    }
  }
  for (i = 0; i < n - 1; i++)
    if (binary_search(a[v[i]].begin(), a[v[i]].end(), v[i + 1])) {
      cout << -1 << endl;
      return 0;
    }
  for (i = 0; i < n; i++) cout << v[i] << " ";
  return 0;
}
