#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> c(n, vector<int>(n));
  vector<vector<double>> a(n, vector<double>(n));
  auto b = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    a[i][i] = c[i][i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      b[i][j] = (c[i][j] - c[j][i]) / 2.0;
      b[j][i] = -b[i][j];
      a[i][j] = a[j][i] = (c[i][j] - b[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.9f ", a[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.9f ", b[i][j]);
    }
    printf("\n");
  }
}
