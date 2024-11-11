#include <bits/stdc++.h>
using namespace std;
vector<int> sh;
int n;
int bs(int l, int r, int x) {
  int mid, i, p;
  mid = l + r;
  mid /= 2;
  if (l >= r) {
    if (sh[l] <= 2 * x)
      return l;
    else
      return -1;
  }
  if (sh[mid] > 2 * x) {
    return bs(l, mid - 1, x);
  } else {
    return max(mid, bs(mid + 1, r, x));
  }
}
int main() {
  int i, j, k, m, p, z = 0;
  long long ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k >= 0)
      sh.push_back(k);
    else
      sh.push_back(-k);
  }
  sort(sh.begin(), sh.end());
  n = sh.size();
  for (i = 0; i < n - 1; i++) {
    p = bs(i + 1, n - 1, sh[i]);
    if (p == -1) continue;
    ans += p - i;
  }
  cout << ans << endl;
  return 0;
}
