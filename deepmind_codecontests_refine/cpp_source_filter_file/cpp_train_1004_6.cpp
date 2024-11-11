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
ModLL dp[51][51][51][51];
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
  dp[0][0][0][0] = 1;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= N; k++) {
        for (int l = 0; l <= N; l++) {
          int ow = j;
          int ew = k;
          int ob = l;
          int eb = i - j - k - l;
          if (eb < 0) continue;
          if (A[i + 1] != 0) {
            ModLL d =
                dp[i][ow][ew][ob] * po2(ob - 1) * po2(eb) * po2(ow) * po2(ew);
            dp[i + 1][ow + 1][ew][ob] +=
                dp[i][ow][ew][ob] * po2(ob - 1) * po2(eb) * po2(ow) * po2(ew);
            if (ob)
              dp[i + 1][ow][ew + 1][ob] +=
                  dp[i][ow][ew][ob] * po2(ob - 1) * po2(eb) * po2(ow) * po2(ew);
          }
          if (A[i + 1] != 1) {
            dp[i + 1][ow][ew][ob + 1] +=
                dp[i][ow][ew][ob] * po2(ow - 1) * po2(ew) * po2(ob) * po2(eb);
            if (ow)
              dp[i + 1][ow][ew][ob] +=
                  dp[i][ow][ew][ob] * po2(ow - 1) * po2(ew) * po2(ob) * po2(eb);
          }
        }
      }
    }
  }
  ModLL ret = 0;
  for (int j = 0; j <= N; j++) {
    for (int k = 0; k <= N; k++) {
      for (int l = 0; l <= N; l++) {
        int ow = j;
        int ew = k;
        int ob = l;
        int eb = N - j - k - l;
        if (eb < 0) continue;
        if ((ow + ob) % 2 == M) continue;
        ret += dp[N][ow][ew][ob];
      }
    }
  }
  cout << ret;
  cin >> N;
  return 0;
}
