#include <bits/stdc++.h>
using namespace std;
long long adj[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}},
          m = 1000000007;
void multiply(long long a[4][4], long long b[4][4]) {
  long long mul[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mul[i][j] = 0;
      for (int k = 0; k < 4; k++) {
        mul[i][j] = (mul[i][j] % m + (adj[i][k] % m * adj[k][j] % m) % m) % m;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) a[i][j] = mul[i][j];
  }
}
void calculate(long long n) {
  long long M[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
  if (n == 1) return;
  calculate(n / 2);
  multiply(adj, adj);
  if (n % 2 == 1) multiply(adj, M);
  return;
}
int main() {
  long long n;
  cin >> n;
  calculate(n);
  cout << adj[3][3] % m << endl;
}
