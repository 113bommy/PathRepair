#include <bits/stdc++.h>
using namespace std;
vector<int> a, d;
int cmp(int va, int i, int vb, int j) {
  if (va < vb)
    return 1;
  else if (va == vb) {
    return i < j;
  } else {
    return 0;
  }
}
int solve(int i, int j) {
  int ans = 0;
  int t = cmp(a[i], i, a[j], j) + cmp(a[i] + d[i], i, a[j], j);
  ans += (t == 1);
  t = cmp(a[i] + d[i], i, a[j], j) + cmp(a[i] + d[i], i, a[j] + d[j], j);
  ans += (t == 1);
  return ans;
}
int main() {
  int n;
  cin >> n;
  a.resize(n);
  d.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> d[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += max(solve(i, j), solve(j, i));
    }
  }
  cout << ans << endl;
  return 0;
}
