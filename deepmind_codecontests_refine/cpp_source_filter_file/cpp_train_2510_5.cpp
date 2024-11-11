#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b, i = 2;
  cin >> b;
  map<long long, long long> divisors;
  while (b != 1 && i * i <= b) {
    if (b % i == 0) {
      b /= i;
      divisors[i]++;
    }
    i++;
  }
  if (b != 1) divisors[b]++;
  long long m = 1;
  for (auto it = divisors.begin(); it != divisors.end(); it++) {
    m *= (it->second + 1);
  }
  cout << m;
  return 0;
}
