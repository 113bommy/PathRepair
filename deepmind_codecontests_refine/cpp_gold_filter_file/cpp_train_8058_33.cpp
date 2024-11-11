#include <bits/stdc++.h>
using namespace std;
const double e = 2.718281828;
void ox90() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int n, m, a[100005], l, reps[100005], ans[100005];
int main() {
  ox90();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i > 0; i--) ans[i] = ans[i + 1] + (reps[a[i]]++ ? 0 : 1);
  for (int i = 0; i < m; i++) {
    cin >> l;
    cout << ans[l] << endl;
  }
}
