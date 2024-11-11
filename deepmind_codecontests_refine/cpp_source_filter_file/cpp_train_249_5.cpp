#include <bits/stdc++.h>
using namespace std;
long long pow(long long x, int n) {
  long long ans = 1;
  while (n--) ans *= x;
  return ans;
}
const int N = 4e4, B = 30;
long long n;
int M[N][B + 1];
int DP(long long a, int b) {
  if (M[a][b] != -1) return M[a][b];
  if (pow(a, b) >= n) return M[a][b] = 2;
  if (a == 1 && pow(2LL, b) >= n) return M[a][b] = 1;
  return M[a][b] = max(2 - DP(a + 1, b), 2 - DP(a, b + 1));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b >> n;
  if (a >= N) {
    long long k = n - a;
    cout << (k % 2 == 0 ? "Masha\n" : "Stas\n");
    return 0;
  }
  for (int i = 0; i < N; ++i)
    for (int j = 0; j <= B; ++j) M[i][j] = -1;
  switch (DP(a, b)) {
    case 2:
      cout << "Masha\n";
      break;
    case 1:
      cout << "Missing\n";
      break;
    case 0:
      cout << "Stas\n";
  }
  return 0;
}
