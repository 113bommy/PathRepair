#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
int arr[100009];
struct data {
  int val;
  int indx;
  long long int cnt;
};
long long solve(int x, int y) {
  stack<data> st;
  st.push({100001000, x, 0});
  long long ans = 0;
  for (int i = x + 1; i <= y; i++) {
    int L = abs(arr[i] - arr[i - 1]);
    while (L > st.top().val) st.pop();
    long long cnt = L * (i - st.top().indx) + st.top().cnt;
    ans += cnt;
    st.push({L, i, cnt});
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int t = 0; t < m; t++) {
    int x, y;
    cin >> x >> y;
    cout << solve(x - 1, y - 1) << endl;
  }
  return 0;
}
