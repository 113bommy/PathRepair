#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
int main(void) {
  int t;
  scanf("%d", &t);
  fill(prime, prime + 1000001, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= 1000; i++) {
    if (!prime[i]) continue;
    for (int j = i * 2; j <= 1000000; j += i) prime[j] = false;
  }
  int size = 1;
  map<int, int> ma;
  ma[1] = 1;
  for (int i = 2; i <= 1000000; i++)
    if (prime[i]) {
      ma[i] = ++size;
    }
  int n;
  while (t--) {
    scanf("%d", &n);
    auto it = ma.upper_bound(n);
    if (it->first > n) it--;
    auto it2 = ma.lower_bound((int)sqrt(n));
    if (it2->first > (int)sqrt(n)) it2--;
    printf("%d\n", it->second - it2->second + 1);
  }
  return 0;
}
