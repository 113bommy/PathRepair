#include <bits/stdc++.h>
struct Factor {
  long long base;
  int deg;
  long long value;
  long long phi() const { return value - value / base; }
  static Factor create(long long base) {
    Factor res;
    res.base = base;
    res.deg = 1;
    res.value = base;
    return res;
  }
};
static long long modulo(const char *buf, int bufLen, long long mod) {
  long long res = 0;
  long long base = 1 % mod;
  for (int i = bufLen - 1; i >= 0; i--) {
    res = (res + (buf[i] - '0') * base) % mod;
    base = (base * 10) % mod;
  }
  return res;
}
static long long power(long long a, long long b, long long mod) {
  long long curPow = a % mod;
  int curIdx = 0;
  long long curRes = 1;
  while (b) {
    if (b & (1LL << curIdx)) {
      b -= (1LL << curIdx);
      curRes = (curRes * curPow) % mod;
    }
    curPow = (curPow * curPow) % mod;
    curIdx++;
  }
  return curRes;
}
static long long findinv(long long n, long long mod, long long p) {
  return power(n, mod - mod / p - 1, mod);
}
static long long power(long long a, const char *b, int blen, long long c) {
  long long bval = -1;
  if (blen <= 9) bval = atol(b);
  std::vector<Factor> factors;
  long long tmp = c;
  for (long long i = 2; i * i <= tmp; i++)
    if (tmp % i == 0) {
      factors.push_back(Factor::create(i));
      tmp /= i;
      while (tmp % i == 0) {
        factors.back().deg++;
        factors.back().value *= i;
        tmp /= i;
      }
    }
  if (tmp > 1) factors.push_back(Factor::create(tmp));
  std::vector<long long> t(factors.size());
  for (int i = 0; i < factors.size(); i++) {
    const Factor &f = factors[i];
    if (a % f.base != 0) {
      long long index = modulo(b, blen, f.phi());
      t[i] = power(a, index, f.value);
    } else {
      if (bval >= 0 && bval < f.deg)
        t[i] = power(a, bval, f.value);
      else
        t[i] = 0;
    }
  }
  std::vector<std::vector<long long> > r(
      factors.size(), std::vector<long long>(factors.size(), 0));
  for (int i = 0; i < factors.size(); i++) {
    for (int j = 0; j < factors.size(); j++)
      if (i != j)
        r[i][j] = findinv(factors[i].value, factors[j].value, factors[j].base);
  }
  std::vector<long long> coefs(factors.size(), 0);
  for (int i = 0; i < factors.size(); i++) {
    coefs[i] = t[i];
    for (int j = 0; j < i; j++) {
      coefs[i] = (r[j][i] * (coefs[i] - coefs[j])) % factors[i].value;
      if (coefs[i] < 0) coefs[i] += factors[i].value;
    }
  }
  long long res = 0;
  for (int i = 0; i < factors.size(); i++) {
    long long coef = 1;
    for (int j = 0; j < i; j++) coef = (coef * factors[j].value) % c;
    res = (res + coefs[i] * coef) % c;
  }
  return res;
}
static char b_read[1048576], n_read[1048576];
int main(int argc, char **argv) {
  long tmp;
  long long c;
  scanf("%s%s%ld", b_read, n_read, &tmp);
  c = tmp;
  int blen = strlen(b_read);
  int nlen = strlen(n_read);
  long long b = modulo(b_read, blen, c);
  for (int i = nlen - 1; i >= 0; i--) {
    if (n_read[i] > '0') {
      n_read[i]--;
      break;
    } else
      n_read[i] = '9';
  }
  long long res = (power(b, n_read, nlen, c) * (b + c - 1)) % c;
  if (res == 0) res = c;
  printf("%ld\n", (long)res);
  return 0;
}
