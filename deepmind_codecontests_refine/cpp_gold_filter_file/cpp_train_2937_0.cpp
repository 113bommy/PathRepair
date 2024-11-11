#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> ms(r, vector<int>(c));
  if (r == 1 && c == 1) {
    cout << 0 << "\n";
    return 0;
  }
  if (r == 1 || c == 1) {
    for (int i = 0; i < max(r, c); i++) {
      cout << i + 2 << "\n";
    }
    return 0;
  }
  for (int i = 0; i < c; i++) {
    ms[0][i] = i + 2;
  }
  for (int i = 1; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ms[i][j] = ms[0][j] * (c + 1 + i);
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << ms[i][j] << (j == c - 1 ? "\n" : " ");
    }
  }
}
