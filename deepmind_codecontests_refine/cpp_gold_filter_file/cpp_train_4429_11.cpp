#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, t = 0, count1 = 0, count2 = 0;
  cin >> n >> c;
  vector<vector<int>> vec(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> vec[i][j];
    }
  }
  for (int j = 0; j < n; ++j) {
    t += vec[1][j];
    if (vec[0][j] - t * c > 0) count1 += vec[0][j] - t * c;
  }
  t = 0;
  for (int j = n - 1; j >= 0; --j) {
    t += vec[1][j];
    if (vec[0][j] - t * c > 0) count2 += vec[0][j] - t * c;
  }
  if (count1 > count2) cout << "Limak";
  if (count1 < count2) cout << "Radewoosh";
  if (count1 == count2) cout << "Tie";
}
