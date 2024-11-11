#include <bits/stdc++.h>
using namespace std;
const long double pi = 4.0 * atanl(1.0);
const long long infll = (long long)(1e18) + 10;
const long long mod = powl(10, 9) + 7;
vector<long long> primesA, primesB, setA, setB;
long long func(long long x) {
  long long a = 0, b = setB.size() - 1;
  long long counter = 0;
  while (a < setA.size() && setA[a] <= x) {
    while (b >= 0 && setA[a] > x / (long double)setB[b]) {
      b--;
    }
    a++;
    counter += b + 1;
  }
  return counter;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long p;
  for (long long i = 0; i < (long long)(n); ++i) {
    cin >> p;
    if (i % 2 == 0) {
      primesA.push_back(p);
    } else {
      primesB.push_back(p);
    }
  }
  setA.push_back(1);
  long long size;
  for (long long p : primesA) {
    size = setA.size();
    long long tempP = p;
    while (true) {
      for (long long i = 0; i < (long long)(size); ++i) {
        if (setA[i] <= (long double)1e18 / tempP)
          setA.push_back(setA[i] * tempP);
      }
      if (tempP > ((long double)1e18) / p) break;
      tempP *= p;
    }
  }
  sort((setA).begin(), (setA).end());
  setB.push_back(1);
  for (long long p : primesB) {
    size = setB.size();
    long long tempP = p;
    while (true) {
      for (long long i = 0; i < (long long)(size); ++i) {
        if (setB[i] <= (long double)1e18 / tempP)
          setB.push_back(setB[i] * tempP);
      }
      if (tempP > ((long double)1e18) / p) break;
      tempP *= p;
    }
  }
  sort((setB).begin(), (setB).end());
  long long k;
  cin >> k;
  long long start = 1, end = (long long)1e18 + 1, mid;
  while (end - start > 1) {
    mid = (start + end) >> 1;
    long long temp = func(mid);
    if (temp >= k) {
      end = mid;
    } else
      start = mid;
  }
  cout << end << '\n';
  return 0;
}
