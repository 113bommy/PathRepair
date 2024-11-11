#include <bits/stdc++.h>
using namespace std;
int memo[5000][5000];
void solve(string a, string b, int alength, int blength) {
  for (int i = 0; i <= alength; i++) {
    for (int j = 0; j <= blength; j++) {
      if (i == 0) {
        memo[i][j] = j;
      } else if (j == 0) {
        memo[i][j] = i;
      } else if (a[i - 1] == b[j - 1]) {
        memo[i][j] = memo[i - 1][j - 1];
      } else {
        memo[i][j] =
            min(memo[i - 1][j], min(memo[i][j - 1], memo[i - 1][j - 1])) + 1;
      }
    }
  }
  cout << memo[alength][blength] << endl;
  int i = alength, j = blength;
  while (j >= 0 || i >= 0) {
    if (memo[i][j] - 1 == memo[i][j - 1]) {
      cout << "INSERT " << i + 1 << ' ' << b[j - 1] << endl;
      j--;
    } else if (memo[i][j] - 1 == memo[i - 1][j]) {
      cout << "DELETE " << i << endl;
      i--;
    } else if (memo[i][j] - 1 == memo[i - 1][j - 1]) {
      cout << "REPLACE " << i << ' ' << b[j - 1] << endl;
      i--;
      j--;
    } else {
      i--;
      j--;
    }
  }
}
int main() {
  memset(memo, -1, sizeof memo);
  string a, b;
  cin >> a >> b;
  solve(a, b, a.size(), b.size());
}
