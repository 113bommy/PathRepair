#include <bits/stdc++.h>
using namespace std;
int A[100010], mk[100010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  int cur = 0, ans = 0;
  set<int> df;
  for (int i = 0; i < n; i++) {
    df.insert(-1 * i);
    while (A[i] >= cur) {
      cur++;
      int x = *df.begin();
      mk[-1 * x] = 1;
      df.erase(df.begin());
    }
  }
  cur = 0;
  for (int i = 0; i < n; i++) {
    if (mk[i]) cur++;
    ans += cur - A[i] - 1;
  }
  cout << ans << '\n';
}
