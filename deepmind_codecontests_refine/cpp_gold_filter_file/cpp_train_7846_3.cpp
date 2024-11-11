#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 3 != 0) {
    cout << 0;
  } else {
    long long k = n / 3;
    set<long long> divisors;
    for (long long i = 1; i * i <= k; i++) {
      if (k % i == 0) {
        divisors.insert(i);
        divisors.insert(k / i);
      }
    }
    int result = 0;
    for (set<long long>::iterator u = divisors.begin();
         u != divisors.end() && (*u) * (*u) * (*u) <= k; u++) {
      for (set<long long>::iterator v = u;
           v != divisors.end() && (*u) * (*v) * (*v) <= k; v++) {
        if (k % ((*u) * (*v)) == 0) {
          long long t = k / ((*u) * (*v));
          if (t < (*u) + (*v) && (t + (*u) + (*v)) % 2 == 0) {
            if (*u == *v && *u == t)
              result += 1;
            else if (*u == *v || *v == t)
              result += 3;
            else
              result += 6;
          }
        }
      }
    }
    cout << result;
  }
  return 0;
}
