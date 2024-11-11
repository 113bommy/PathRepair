#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n;
  cin >> n;
  vector<long double> probs(n);
  for (i = 0; i < n; i++) {
    cin >> probs[i];
  }
  sort(probs.begin(), probs.end());
  reverse(probs.begin(), probs.end());
  long double prob0 = 1;
  long double prob1 = 0.;
  for (i = 0; i < n; i++) {
    long double p = prob1;
    p = probs[i] * prob0 + p * (1 - probs[i]);
    if (p > prob1) {
      prob1 = p;
      prob0 = (1 - probs[i]) * prob0;
    }
  }
  printf("%.9lf", double(prob1 + 0.0000000001));
  return 0;
}
