#include <bits/stdc++.h>
using namespace std;
template <class T>
T Mul(T x, T y, T P) {
  T F1 = 0;
  while (y) {
    if (y & 1) {
      F1 += x;
      if (F1 < 0 || F1 >= P) F1 -= P;
    }
    x <<= 1;
    if (x < 0 || x >= P) x -= P;
    y >>= 1;
  }
  return F1;
}
template <class T>
T Pow(T x, T y, T P) {
  T F1 = 1;
  x %= P;
  while (y) {
    if (y & 1) {
      F1 = Mul(F1, x, P);
    }
    x = Mul(x, x, P);
    y >>= 1;
  }
  return F1;
}
template <class T>
T Gcd(T x, T y) {
  if (y == 0) return x;
  T z;
  while (z = x % y) {
    x = y, y = z;
  }
  return y;
}
template <class T>
void UpdateMin(T& x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdateMax(T& x, T y) {
  if (x < y) {
    x = y;
  }
}
template <class T>
T Sqr(const T x) {
  return x * x;
}
template <class T>
T Abs(const T x) {
  return x < 0 ? -x : x;
}
class ReadBuffer {
 private:
  char buff[20000000];
  char* buf;

 public:
  void init(int size = 20000000) {
    fread(buff, 1, size, stdin);
    buf = buff;
  }
  template <class T>
  bool readInteger(T& x) {
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag;
    flag = 0;
    if (*buf == '-')
      flag = true;
    else
      x = *buf - '0';
    while (isdigit(*++buf)) x = x * 10 + *buf - '0';
    if (flag) x = -x;
    return true;
  }
  template <class T>
  bool readFloat(T& x) {
    long double nowpos = 0.1;
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag, decimal;
    decimal = flag = 0;
    if (*buf == '-')
      flag = true, ++buf;
    else if (*buf == '.')
      decimal = true;
    while (isdigit(*buf) || *buf == '.') {
      if (*buf == '.')
        decimal = true;
      else {
        if (decimal) {
          x += nowpos * (*buf - '0');
          nowpos *= 0.1;
        } else {
          x = x * 10 + *buf - '0';
        }
      }
      ++buf;
    }
    return true;
  }
  bool readChar(char c) {
    if (*buf == 0) return 0;
    return c = *buf++, 1;
  }
  bool readString(char* s) {
    while (*buf && isspace(*buf)) ++buf;
    if (!*buf) return false;
    while (!isspace(*buf)) *s++ = *buf++;
    *s++ = 0;
    return true;
  }
  int countSpacetonext() {
    int total = 0;
    while (*buf && *buf == ' ') ++total, ++buf;
    return total;
  }
  bool splitBycharactor(char* s, char Split = '\n') {
    while (*buf && *buf != Split) *s++ = *buf++;
    *s++ = 0;
    return *buf != 0;
  }
};
struct EDGE {
  int T;
  EDGE* Nxt;
};
const int mod = 1000000007;
int tmpA[20][30001];
int tmpB[20][30001];
int tmpC[20][30001];
int tmpD[20][30001];
int tmpE[20][30001];
unsigned long long tmpsD[40], tmpsE[40];
void multiply2(const int* const& A, const int* const& B, const int* const& C,
               int* const& D, int* const& E, int const& len, int const& id) {
  if (len < 18) {
    for (int i = 1; i <= (len); ++i)
      for (int j = 1; j <= (len); ++j) {
        tmpsD[i + j] += (long long)A[i] * C[j];
        tmpsE[i + j] += (long long)B[i] * C[j];
      }
    for (int i = 1; i <= (len * 2); ++i) {
      D[i] = tmpsD[i] % mod;
      tmpsD[i] = 0;
      E[i] = tmpsE[i] % mod;
      tmpsE[i] = 0;
    }
    return;
  }
  int halflen = len >> 1, halflen2 = len - halflen;
  const int* const AA = A + halflen;
  const int* const BB = B + halflen;
  const int* const CC = C + halflen;
  int* const DD = D + halflen + halflen;
  int* const EE = E + halflen + halflen;
  multiply2(A, B, C, D, E, halflen, id);
  multiply2(AA, BB, CC, DD, EE, halflen2, id);
  int* const NA = tmpA[id];
  int* const NB = tmpB[id];
  int* const NC = tmpC[id];
  int* const ND = tmpD[id];
  int* const NE = tmpE[id];
  for (int i = 1; i <= (halflen); ++i) {
    NA[i] = A[i];
    if ((NA[i] += AA[i]) >= mod) NA[i] -= mod;
    NB[i] = B[i];
    if ((NB[i] += BB[i]) >= mod) NB[i] -= mod;
    NC[i] = C[i];
    if ((NC[i] += CC[i]) >= mod) NC[i] -= mod;
  }
  if (halflen2 != halflen) {
    NA[halflen2] = AA[halflen2];
    NB[halflen2] = BB[halflen2];
    NC[halflen2] = CC[halflen2];
  }
  multiply2(NA, NB, NC, ND, NE, halflen2, id + 1);
  for (int i = 1; i <= (halflen * 2); ++i) {
    if ((ND[i] += mod - D[i]) >= mod) ND[i] -= mod;
    if ((ND[i] += mod - DD[i]) >= mod) ND[i] -= mod;
    if ((NE[i] += mod - E[i]) >= mod) NE[i] -= mod;
    if ((NE[i] += mod - EE[i]) >= mod) NE[i] -= mod;
  }
  if (halflen2 != halflen) {
    if ((ND[halflen2 * 2 - 1] += mod - DD[halflen2 * 2 - 1]) >= mod)
      ND[halflen2 * 2 - 1] -= mod;
    if ((ND[halflen2 * 2] += mod - DD[halflen2 * 2]) >= mod)
      ND[halflen2 * 2] -= mod;
    if ((NE[halflen2 * 2 - 1] += mod - EE[halflen2 * 2 - 1]) >= mod)
      NE[halflen2 * 2 - 1] -= mod;
    if ((NE[halflen2 * 2] += mod - EE[halflen2 * 2]) >= mod)
      NE[halflen2 * 2] -= mod;
  }
  for (int i = 1; i <= (halflen2 * 2); ++i) {
    if ((D[i + halflen] += ND[i]) >= mod) D[i + halflen] -= mod;
    if ((E[i + halflen] += NE[i]) >= mod) E[i + halflen] -= mod;
    ND[i] = NE[i] = 0;
  }
}
void multiply(const int* const& A, const int* const& B, int* const& D,
              int const& len, int const& id) {
  if (len < 18) {
    for (int i = 1; i <= (len); ++i)
      for (int j = 1; j <= (len); ++j) {
        tmpsD[i + j] += (long long)A[i] * B[j];
      }
    for (int i = 1; i <= (len * 2); ++i) {
      D[i] = tmpsD[i] % mod;
      tmpsD[i] = 0;
    }
    return;
  }
  int halflen = len >> 1, halflen2 = len - halflen;
  const int* const AA = A + halflen;
  const int* const BB = B + halflen;
  int* const DD = D + halflen + halflen;
  multiply(A, B, D, halflen, id);
  multiply(AA, BB, DD, halflen2, id);
  int* const NA = tmpA[id];
  int* const NB = tmpB[id];
  int* const ND = tmpD[id];
  for (int i = 1; i <= (halflen); ++i) {
    NA[i] = A[i];
    if ((NA[i] += AA[i]) >= mod) NA[i] -= mod;
    NB[i] = B[i];
    if ((NB[i] += BB[i]) >= mod) NB[i] -= mod;
  }
  if (halflen2 != halflen) {
    NA[halflen2] = AA[halflen2];
    NB[halflen2] = BB[halflen2];
  }
  multiply(NA, NB, ND, halflen2, id + 1);
  for (int i = 1; i <= (halflen * 2); ++i) {
    if ((ND[i] += mod - D[i]) >= mod) ND[i] -= mod;
    if ((ND[i] += mod - DD[i]) >= mod) ND[i] -= mod;
  }
  if (halflen2 != halflen) {
    if ((ND[halflen2 * 2 - 1] += mod - DD[halflen2 * 2 - 1]) >= mod)
      ND[halflen2 * 2 - 1] -= mod;
    if ((ND[halflen2 * 2] += mod - DD[halflen2 * 2]) >= mod)
      ND[halflen2 * 2] -= mod;
  }
  for (int i = 1; i <= (halflen2 * 2); ++i) {
    if ((D[i + halflen] += ND[i]) >= mod) D[i + halflen] -= mod;
    ND[i] = 0;
  }
}
int polyA[60001];
int polyB[60001];
int polyC[60001];
int polyD[70001];
int polyE[70001];
long long N, K;
long long fact[30001];
long long invfact[30001];
long long inv[30001];
int main() {
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= (30000); ++i) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = i == 1 ? 1LL : mod - mod / i * inv[mod % i] % mod;
    invfact[i] = invfact[i - 1] * inv[i] % mod;
  }
  cin >> N >> K;
  if (N > K) {
    printf("0\n");
    return 0;
  }
  long long NP = 2;
  for (int i = 1; i <= (K); ++i) polyA[i] = polyB[i] = 1;
  --N;
  int preZero = 0;
  for (int msk = 1; msk <= N; msk <<= 1) {
    for (int i = 1; i <= (K); ++i) {
      polyC[i] = polyB[i] * invfact[i] % mod;
    }
    if (N & msk) {
      register long long NPP = NP;
      for (int i = 1; i <= (K); ++i) {
        polyA[i] = polyA[i] * NPP % mod * invfact[i] % mod;
        polyB[i] = polyC[i] * NPP % mod;
        NPP = NPP * NP % mod;
      }
      multiply2(polyA + preZero, polyB + msk - 1, polyC + msk - 1,
                polyD + preZero + msk - 1, polyE + msk * 2 - 2,
                K - preZero - msk + 1, 0);
      for (int i = 1; i <= (K); ++i) {
        polyA[i] = polyD[i] * fact[i] % mod;
        polyD[i] = polyD[K + i] = 0;
        polyB[i] = polyE[i] * fact[i] % mod;
        polyE[i] = polyE[K + i] = 0;
      }
      preZero += msk;
    } else {
      register long long NPP = NP;
      for (int i = 1; i <= (K); ++i) {
        polyB[i] = polyC[i] * NPP % mod;
        NPP = NPP * NP % mod;
      }
      multiply(polyB + msk - 1, polyC + msk - 1, polyE + 2 * msk - 2,
               K - 2 * msk + 2, 0);
      for (int i = 1; i <= (K); ++i) {
        polyB[i] = polyE[i] * fact[i] % mod;
        polyE[i] = polyE[K + i] = 0;
      }
    }
    NP = NP * NP % mod;
  }
  long long ans = 0;
  for (int i = (N); i <= (K); ++i) {
    ans = (ans + polyA[i] * invfact[i] % mod * invfact[K - i]) % mod;
  }
  cout << ans * fact[K] % mod << endl;
  cin >> N;
  return 0;
}
