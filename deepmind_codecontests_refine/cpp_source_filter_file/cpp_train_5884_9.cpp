#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)1e18;
vector<long long> V;
int main() {
  int res = 0;
  long long a, b;
  for (long long i = 4, k = 3; k <= MAX; k += i, i *= 2) {
    for (long long j = 1; j < k / 2; j *= 2) {
      V.push_back(k - j);
    }
  }
  scanf("%lld %lld", &a, &b);
  for (int i = 0; i < V.size(); i++) {
    if (V[i] >= a && V[i] <= b) {
      res++;
    }
  }
  printf("%d\n", res);
}
