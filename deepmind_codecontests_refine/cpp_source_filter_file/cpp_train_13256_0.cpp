#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l;
  cin >> n >> l;
  long long count[3001][200];
  int length[200], width[200];
  for (int i = 0; i < 2 * n; i += 2) {
    cin >> length[i] >> width[i];
    if (length[i] != width[i]) {
      length[i + 1] = width[i];
      width[i + 1] = length[i];
    } else {
      length[i + 1] = -1;
      width[i + 1] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      count[i][j] = 0;
    }
  }
  for (int j = 0; j < 2 * n; ++j) {
    if (length[j] <= l && length[j] > 0) {
      count[length[j]][j] = 1;
    }
  }
  for (int i = 1; i <= l; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      if (length[j] <= 0) {
        continue;
      }
      int w = width[j];
      for (int k = 0; k < 2 * n; ++k) {
        if (length[k] == w && k / 2 != j / 2 && i + length[k] <= l) {
          count[i + length[k]][k] += count[i][j];
          count[i + length[k]][k] %= 1000000007;
        }
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < 2 * n; ++i) {
    sum += count[l][i];
    sum %= 1000000007;
  }
  cout << sum << endl;
}
