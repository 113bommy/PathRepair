#include <bits/stdc++.h>
using namespace std;
int a[200001], b[200001], st1[20][200001], st2[20][200001], n;
void build1() {
  for (int j = 0; j <= 18; j++) {
    for (int i = 0; i <= n; i++) {
      if (j == 0)
        st1[j][i] = a[i];
      else if ((1 << j) + i - 1 > n)
        st1[j][i] = -1;
      else
        st1[j][i] = max(st1[j - 1][i], st1[j - 1][i + (1 << (j - 1))]);
    }
  }
}
void build2() {
  for (int j = 0; j <= 18; j++) {
    for (int i = 0; i <= n; i++) {
      if (j == 0)
        st2[j][i] = b[i];
      else if ((1 << j) + i - 1 > n)
        st2[j][i] = -1;
      else
        st2[j][i] = min(st2[j - 1][i], st2[j - 1][i + (1 << (j - 1))]);
    }
  }
}
int query1(int l, int r) {
  int diff = r - l + 1, j;
  for (j = 0; (1 << j) <= diff; j++)
    ;
  j--;
  int ans = st1[j][l];
  l += (1 << j);
  diff = r - l + 1;
  if (diff <= 0)
    return ans;
  else
    return max(ans, query1(l, r));
}
int query2(int l, int r) {
  int diff = r - l + 1, j;
  for (j = 0; (1 << j) <= diff; j++)
    ;
  j--;
  int ans = st2[j][l];
  l += (1 << j);
  diff = r - l + 1;
  if (diff <= 0)
    return ans;
  else
    return min(ans, query2(l, r));
}
long long int solve(int x, int l, int r, int l1, int r1) {
  if (l > r) return 0;
  if (l == r) {
    int t1 = query1(x, r);
    int t2 = query2(x, r);
    if (t1 == t2)
      return 1ll;
    else
      return 0ll;
  }
  int mid = (l + r) / 2;
  int t1 = query1(x, mid);
  int t2 = query2(x, mid);
  if (t1 == t2) {
    if (l1 != -1) {
      return (solve(x, l, mid - 1, 1, -1) + (r - mid));
    } else if (r1 != -1) {
      return (solve(x, mid + 1, r, -1, 1) + (mid - l));
    } else
      return (1 + solve(x, l, mid - 1, 1, -1) + solve(x, mid + 1, r, -1, 1));
  } else if (t1 < t2) {
    return (solve(x, mid + 1, r, -1, -1));
  } else
    return solve(x, l, mid - 1, -1, -1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  build1();
  build2();
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += solve(i, i, n - 1, -1, -1);
  }
  cout << ans << "\n";
}
