#include <bits/stdc++.h>
using namespace std;
int prod(vector<int> A, vector<int> B) {
  int ans = 0;
  for (int i = 0; i < A.size(); i++) ans += A[i] * B[i];
  return ans;
}
int main() {
  int n;
  cin >> n;
  if (n > 100) {
    cout << "0\n";
    return 0;
  }
  vector<vector<int> > A(n, vector<int>(5));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) cin >> A[i][j];
  vector<int> ans;
  for (int a = 0; a < n; a++) {
    int ok = true;
    for (int b = 0; b < n && ok; b++)
      if (b != a)
        for (int c = b + 1; c < n && ok; c++)
          if (c != a) {
            vector<int> x(5), y(5);
            for (int j = 0; j < 5; j++) {
              x[j] = A[b][j] - A[a][j];
              y[j] = A[c][j] - A[a][j];
            }
            int xy = prod(x, y);
            if (xy > 0) {
              ok = false;
            }
          }
    if (ok) ans.push_back(a + 1);
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x << endl;
  return 0;
}
