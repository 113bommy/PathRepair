#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long m, h1, x1, Y1, a1, h2, x2, y2, a2;
int main() {
  cin >> m >> h1 >> a1 >> x1 >> Y1 >> h2 >> a2 >> x2 >> y2;
  long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
  long long n1 = -1, m1 = -1, n2 = -1, m2 = -1;
  while (cnt1 < 2 * m + 10) {
    if (h1 == a1 && cnt3 == 0) {
      m1 = cnt1;
      cnt3++;
    } else if (h1 == a1 && cnt3 == 1) {
      n1 = cnt1 - m1;
      break;
    }
    h1 = (x1 * h1 + Y1) % m;
    cnt1++;
  }
  cnt3 = 0;
  while (cnt2 < 2 * m + 10) {
    if (h2 == a2 && cnt3 == 0) {
      m2 = cnt2;
      cnt3++;
    } else if (h2 == a2 && cnt3 == 1) {
      n2 = cnt2 - m2;
      break;
    }
    h2 = (x2 * h2 + y2) % m;
    cnt2++;
  }
  long long p = -1, q = -1;
  if (n1 == -1 && n2 == -1) {
    if (m1 == m2)
      cout << m1 << endl;
    else
      cout << "-1" << endl;
  } else if (n1 == -1) {
    if (m1 - m2 > 0 && (m1 - m2) % n2 == 0)
      cout << m1 << endl;
    else
      cout << "-1" << endl;
  } else if (n2 == -1) {
    if (m2 - m1 > 0 && (m2 - m1) % n1 == 0)
      cout << m2 << endl;
    else
      cout << "-1" << endl;
  } else {
    for (int i = 0; i < (int)n2; i++) {
      if ((n1 * i + n2 + m1 - m2) % n2 == 0) {
        p = i;
        break;
      }
    }
    if (p == -1)
      cout << "-1" << endl;
    else {
      q = (n1 * p + m1 - m2) / n2;
      long long k = (q >= 0) ? 0 : ((-q + n1 - 1) / n1);
      cout << m1 + n1 * (n2 * k + p) << endl;
    }
  }
}
