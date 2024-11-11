#include <bits/stdc++.h>
using namespace std;
int N, M, K, L, Q;
struct ModLL {
  long long value;
  ModLL() { value = 0; }
  ModLL(long long value) { this->value = value; }
  ModLL(int value) { this->value = value; }
  ModLL& operator=(const ModLL& rhs) {
    value = rhs.value;
    return *this;
  }
  ModLL& operator=(int rhs) {
    value = rhs;
    return *this;
  }
  ModLL& operator=(long long rhs) {
    value = rhs;
    return *this;
  }
  ModLL operator+(const ModLL& rhs) {
    return ModLL(ModLL{(value + rhs.value) % 1000000007});
  }
  ModLL operator-(const ModLL& rhs) {
    return ModLL(
        ModLL{((value - rhs.value) % 1000000007 + 1000000007) % 1000000007});
  }
  ModLL operator*(const ModLL& rhs) {
    return ModLL(
        ModLL{((value * rhs.value) % 1000000007 + 1000000007) % 1000000007});
  }
  ModLL operator+(long long rhs) {
    return ModLL(ModLL{(value + rhs) % 1000000007});
  }
  ModLL operator-(long long rhs) {
    return ModLL(ModLL{((value - rhs) % 1000000007 + 1000000007) % 1000000007});
  }
  ModLL operator*(long long rhs) {
    return ModLL(ModLL{((value * rhs) % 1000000007 + 1000000007) % 1000000007});
  }
  ModLL& operator+=(const ModLL& rhs) {
    *this = *this + rhs;
    return *this;
  }
  ModLL& operator-=(const ModLL& rhs) {
    *this = *this - rhs;
    return *this;
  }
  ModLL& operator*=(const ModLL& rhs) {
    *this = *this * rhs;
    return *this;
  }
  ModLL& operator+=(long long rhs) {
    *this = *this + rhs;
    return *this;
  }
  ModLL& operator-=(long long rhs) {
    *this = *this - rhs;
    return *this;
  }
  ModLL& operator*=(long long rhs) {
    *this = *this * rhs;
    return *this;
  }
};
std::ostream& operator<<(std::ostream& stream, const ModLL& modLL) {
  stream << modLL.value;
  return stream;
}
long long FastPow(long long base, long long po, long long mod) {
  long long ret = 1;
  while (po) {
    if (po & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    po = (po >> 1);
  }
  return ret;
}
long long A[5003];
ModLL RA[5003];
ModLL COST[5003];
ModLL RCOST[5003];
ModLL COUNT[5003];
ModLL DP[5003][5003];
ModLL ret[20000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  A[N] = 1;
  for (int i = 1; i < N; i++) {
    cin >> A[i];
    RA[i] = FastPow(A[i], 1000000007 - 2, 1000000007);
  }
  COST[N] = 1;
  for (int i = N - 1; i > 0; i--) COST[i] = COST[i + 1] * A[i];
  for (int i = 1; i <= N; i++)
    RCOST[i] = FastPow(COST[i].value, 1000000007 - 2, 1000000007);
  COUNT[1] = 1;
  for (int i = 2; i <= N; i++) {
    COUNT[i] = COUNT[i - 1] * A[i - 1];
  }
  for (int i = N; i > 0; i--) {
    for (int j = 0; j <= N; j++) {
      DP[i][j] =
          ((i + 1 <= N && j + 1 <= N) ? DP[i + 1][j + 1] : 0) +
          (j == 0 ? 1
                  : (i + j <= N ? COST[i] * RCOST[i + j] * RA[i] * (A[i] - 1)
                                : 0));
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 2 * N - 2; j++) {
      ModLL down = (i + j <= N ? COST[i] * RCOST[i + j] : 0);
      int up_idx = max(1, i - j);
      int up_len = i - up_idx;
      int up_go = j - up_len;
      ModLL up =
          (up_go > N
               ? 0
               : max(0LL, (DP[up_idx][up_go] - (j <= N ? DP[i][j] : 0)).value));
      ret[j] += (down + up) * COUNT[i];
    }
  }
  long long div = FastPow(2, 1000000007 - 2, 1000000007);
  for (int i = 1; i <= 2 * N - 2; i++) cout << ret[i] * div << " ";
  cin >> N;
}
