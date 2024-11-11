#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr(5, vector<int>(200005));
int main() {
  int t, n, i, ans, a, b, c, d, e, m, j, s, curr;
  string s1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> s1;
      a = 0;
      b = 0;
      c = 0;
      d = 0;
      e = 0;
      m = s1.size();
      for (j = 0; j < m; j++) {
        if (s1[j] == 'a')
          a++;
        else if (s1[j] == 'b')
          b++;
        else if (s1[j] == 'c')
          c++;
        else if (s1[j] == 'd')
          d++;
        else if (s1[j] == 'e')
          e++;
      }
      arr[0][i] = a - (m - a);
      arr[1][i] = b - (m - b);
      arr[2][i] = c - (m - c);
      arr[3][i] = d - (m - d);
      arr[4][i] = e - (m - e);
    }
    for (i = 0; i < 5; i++)
      sort(arr[i].begin(), arr[i].begin() + n, greater<int>());
    ans = 0;
    for (i = 0; i < 5; i++) {
      curr = 0;
      j = 0;
      s = 0;
      while (j < n && arr[i][j] > 0) {
        s += arr[i][j];
        curr++;
        j++;
      }
      while (j < n && (s + arr[i][j]) > 0) {
        s += arr[i][j];
        curr++;
        j++;
      }
      ans = max(ans, curr);
    }
    cout << ans << endl;
  }
  return 0;
}
