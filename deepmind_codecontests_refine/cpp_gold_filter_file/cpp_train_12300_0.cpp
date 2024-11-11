#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, ta, tb, k, t;
vector<int> a, b;
int bins(int r) {
  int i = 0, j = b.size() - 1, mid;
  while (j - i > 1) {
    mid = (j + i) / 2;
    if (b[mid] > r)
      j = mid;
    else
      i = mid;
  }
  if (b[i] >= r) return i;
  if (b[j] >= r) return j;
  return -1;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    a.push_back(t);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    b.push_back(t);
  }
  long long mx = 0;
  for (int i = 0; i < k + 1; i++) {
    if (i >= a.size()) {
      cout << -1;
      return 0;
    }
    int z = ta + a[i];
    int id = bins(z);
    if (id == -1 || (b.size() - id) <= (k - i)) {
      cout << -1;
      return 0;
    }
    long long q = tb + b[id + k - i];
    mx = max(mx, q);
  }
  cout << mx;
}
