#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  long long ans = 0;
  int n, m, k;
  cin >> n >> m >> k;
  int pos[100001], order[100001];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
    order[i] = x;
  }
  for (int i = 0; i < m; i++) {
    int in;
    cin >> in;
    if (pos[in] < k)
      ans++;
    else
      ans += pos[in] / k + 1;
    if (pos[in] != 0) {
      pos[in]--;
      pos[order[pos[in]]]++;
      iter_swap(&order[pos[in]], &order[pos[in] + 1]);
    }
  }
  cout << ans << endl;
}
