#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 2e9;
int A[N], B[N], n, m;
long long check(int x) {
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (A[i] < x) ans += x - A[i];
  for (int i = 0; i < m; i++)
    if (B[i] > x) ans += B[i] - x;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++) cin >> B[i];
  int l = min(*min_element(A, A + n), *min_element(B, B + m)),
      r = max(*max_element(A, A + n), *max_element(B, B + m));
  while (r - l > 2) {
    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (check(m1) > check(m2))
      l = m1;
    else
      r = m2;
  }
  cout << min({check(l), check(r), ((r - l == 2) ? check(l + 1) : inf)});
}
