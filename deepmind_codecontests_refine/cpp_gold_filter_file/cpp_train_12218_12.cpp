#include <bits/stdc++.h>
using namespace std;
int solve(void) {
  int N, M, ans = 0, arr[30];
  string p;
  cin >> N >> M;
  memset(arr, 0, sizeof arr);
  for (int i = 0, tans = 0; i < (int)N; i += 1) {
    cin >> p;
    for (int j = 0; j < (int)M; j += 1)
      if (p[j] == '0')
        arr[j]++;
      else
        arr[j] = 0;
    for (int xp = 0; xp < (int)M; xp += 1) {
      for (int en = xp; en < (int)M; en += 1) {
        if (*min_element(arr + xp, arr + en + 1))
          tans = 2 * (*min_element(arr + xp, arr + en + 1) + (en - xp + 1));
        ans = max(ans, tans);
      }
    }
  }
  cout << ans << endl;
  ;
  return 0;
}
int main(void) {
  solve();
  return 0;
}
