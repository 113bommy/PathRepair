#include <bits/stdc++.h>
using namespace std;
int nrq, n, k, mini, ans;
char sir[200005], sir2[200005], arr[200005];
int main() {
  int i, j;
  char s[3][3] = {{'R', 'G', 'B'}, {'B', 'R', 'G'}, {'G', 'B', 'R'}};
  cin >> nrq;
  while (nrq--) {
    cin >> n >> k >> sir;
    ans = 1e9;
    for (j = 0; j < 3; j++) {
      for (i = 0; i < n; i++) {
        sir2[i] = s[j][i % 3];
      }
      for (i = 0; i < n; i++)
        if (sir[i] != sir2[i])
          arr[i] = 1;
        else
          arr[i] = 0;
      for (i = 1; i < n; i++) arr[i] += arr[i - 1];
      mini = arr[k - 1];
      for (i = k; i < n; i++) mini = min(mini, arr[i] - arr[i - k]);
      ans = min(ans, mini);
    }
    cout << ans << "\n";
  }
  return 0;
}
