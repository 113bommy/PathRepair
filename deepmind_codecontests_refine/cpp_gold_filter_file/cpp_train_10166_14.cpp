#include <bits/stdc++.h>
using namespace std;
int prime[100005] = {0};
long long p2 = 0;
vector<long long> vec;
void sieve(long long n) {
  prime[1] = 1;
  long long i = 0;
  for (i = 2; i < n; i++) {
    if (!prime[i]) {
      for (long long j = 2 * i; j < n; j += i) {
        prime[j] = 1;
      }
      if (i <= p2)
        vec.push_back(i);
      else
        break;
    }
  }
}
int main() {
  ;
  long long p, y;
  ;
  ;
  scanf("%lld", &p);
  ;
  ;
  scanf("%lld", &y);
  ;
  ;
  ;
  p2 = p;
  sieve(100005);
  long long i = 0;
  if (y % 2 == 0) y--;
  while (y > p) {
    for (i = 0; i < vec.size(); i++) {
      if (y % vec[i] == 0) break;
    }
    if (i == vec.size()) {
      ;
      printf("%lld\n", y);
      return 0;
    }
    y -= 2;
  }
  printf("-1\n");
  return 0;
  return 0;
}
