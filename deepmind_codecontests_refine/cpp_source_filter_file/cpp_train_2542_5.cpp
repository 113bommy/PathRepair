#include <bits/stdc++.h>
using namespace std;
const int maxv = 100;
int cnt[maxv + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    cnt[v]++;
  }
  int ans = 0;
  while (n) {
    ans++;
    int dem = 0;
    for (int v = 0; v <= maxv; v++)
      if (cnt[v] && v >= dem) {
        cnt[v]--;
        n--;
        dem++;
      }
  }
  cout << ans << "\n";
}
