#include <bits/stdc++.h>
using namespace std;
const int mxN = 3 * 1e5 + 10;
int lastIndex[mxN];
int lowestThatWork[mxN];
int ans[mxN];
const int inf = 1e7;
int main() {
  cout.sync_with_stdio(0);
  cin.tie();
  int t, n;
  int x;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      lowestThatWork[i] = 0;
      lastIndex[i] = -1;
      ans[i] = inf;
    }
    ans[n] = inf;
    for (int i = 0; i < n; i++) {
      cin >> x;
      x--;
      int cd = i - lastIndex[x];
      lastIndex[x] = i;
      lowestThatWork[x] = max(cd, lowestThatWork[x]);
    }
    for (int i = 0; i < n; i++) {
      lowestThatWork[i] = max(n - lastIndex[i], lowestThatWork[i]);
      ans[lowestThatWork[i]] = min(ans[lowestThatWork[i]], i);
    }
    int lastAnswer = -1;
    for (int i = 1; i <= n; i++) {
      if (ans[i] == inf || (lastAnswer != -1 && lastAnswer <= ans[i])) {
        cout << lastAnswer << " ";
      } else {
        cout << ans[i] + 1 << " ";
        lastAnswer = ans[i] + 1;
      }
    }
    cout << "\n";
  }
}
