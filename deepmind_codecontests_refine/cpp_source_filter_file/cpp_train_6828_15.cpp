#include <bits/stdc++.h>
using namespace std;
int main(void) {
  std::ios::sync_with_stdio(false);
  int n, p, k, result;
  cin >> n;
  vector<int> v(n);
  vector<int> templ(320, 1);
  vector<vector<int> > len(n, templ);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 320; j++) {
      if (i + j + v[i] >= n) {
        len[i][j] = 1;
        break;
      } else {
        len[i][j] = 1 + len[i + v[i] + j][j];
      }
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> k;
    p--;
    result = 0;
    if (k > 319) {
      while (p < n) {
        p += v[p] + k;
        result++;
      }
      cout << result;
    } else {
      cout << len[p][k];
    }
    cout << '\n';
  }
  return 0;
}
