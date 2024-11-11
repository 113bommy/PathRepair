#include <bits/stdc++.h>
using namespace std;
int Q, N, M, K, L;
struct ModLL {
  long long value;
  ModLL() { this->value = 0; }
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
ModLL dp[51][51][51];
ModLL po[51];
int A[51];
ModLL po2(int n) {
  if (n < 0) return 1;
  return po[n];
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  po[0] = 1;
  for (int i = 1; i < 51; i++) po[i] = po[i - 1] * 2;
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= N; k++) {
        int ow = j;
        int ob = k;
        int evens = i - ow - ob;
        if (evens < 0) continue;
        if (A[i + 1] != 0) {
          dp[i + 1][ow + 1][ob] +=
              dp[i][ow][ob] * po2(ob - 1) * po2(ow) * po2(evens);
          if (ob)
            dp[i + 1][ow][ob] +=
                dp[i][ow][ob] * po2(ob - 1) * po2(ow) * po2(evens);
        }
        if (A[i + 1] != 1) {
          dp[i + 1][ow][ob + 1] +=
              dp[i][ow][ob] * po2(ow - 1) * po2(ob) * po2(evens);
          if (ow)
            dp[i + 1][ow][ob] +=
                dp[i][ow][ob] * po2(ow - 1) * po2(ob) * po2(evens);
        }
      }
    }
  }
  ModLL ret = 0;
  for (int j = 0; j <= N; j++) {
    for (int k = 0; k <= N; k++) {
      int ow = j;
      int ob = k;
      int evens = N - ow - ob;
      if (evens < 0) continue;
      if ((ow + ob) % 2 != M) continue;
      ret += dp[N][ow][ob];
    }
  }
  cout << ret;
  cin >> N;
  return 0;
}
