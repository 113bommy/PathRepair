#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
  if (!a) return b;
  return GCD(b % a, a);
}
void init() {}
vector<int> a, b;
long long dp[44][44][44], A[44][44], ret[44][44];
int n;
void printMat(long long A[44][44]) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
void matMul(long long A[44][44], long long B[44][44],
            long long target[44][44]) {
  long long C[44][44];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      C[i][j] = (1LL << 50);
      for (int k = 0; k <= n; k++) {
        C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      target[i][j] = C[i][j];
    }
  }
}
long long solve(int at, int curB, int toB) {
  if (curB < 0 || curB > n) return (1LL << 50);
  long long &ret = dp[at][curB][toB];
  if (ret != -1) return ret;
  if (at == n) {
    if (curB == toB) return 0;
    return (1LL << 50);
  }
  ret = (1LL << 50);
  ret = a[at % n] + solve(at + 1, curB + 1, toB);
  ret = min(ret, b[at % n] + solve(at + 1, curB - 1, toB));
  return ret;
}
int main() {
  clock_t startTime = clock();
  init();
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    a.push_back(p);
  }
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    b.push_back(p);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      A[i][j] = solve(0, i, j);
      ret[i][j] = (1LL << 50);
    }
  }
  ret[0][0] = 0;
  while (m > 0) {
    if (m & 1) {
      matMul(ret, A, ret);
    }
    matMul(A, A, A);
    m >>= 1;
  }
  cout << ret[0][0] << "\n";
  clock_t endTime = clock();
  cerr << "\nTime: " << double(endTime - startTime) / CLOCKS_PER_SEC
       << " seconds" << endl;
  return 0;
}
