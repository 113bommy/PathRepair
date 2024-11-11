#include <bits/stdc++.h>
using namespace std;
bool np[32005];
vector<int> prime;
int ps;
void sieve(int n) {
  for (int i = (2); i <= (n); i++) {
    if (np[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= n; j += i) np[j] = 1;
  }
  ps = prime.size();
}
int k;
int recur(int i, long long pdt, long long req, int q) {
  if (!q) return req / pdt;
  if (i == ps) return 0;
  if (prime[i] >= k ||
      pow(double(req) / pdt, double(1) / q) < double(prime[i]) - 5)
    return 0;
  int r = 0;
  if (pdt * prime[i] <= req) r += recur(i + 1, pdt * prime[i], req, q - 1);
  r += recur(i + 1, pdt, req, q);
  return r;
}
int query(int n) {
  int sum = n / k;
  for (int i = (1); i <= (9); i++) {
    if (i & 1)
      sum -= recur(0, 1, n / k, i);
    else
      sum += recur(0, 1, n / k, i);
  }
  return sum;
}
int main() {
  sieve(32000);
  int a, b;
  scanf("%d %d %d", &a, &b, &k);
  for (auto p : prime) {
    if (p * p > k) break;
    if (k % p == 0) {
      printf("0\n");
      return 0;
    }
  }
  printf("%d\n", query(b) - query(a - 1));
  return 0;
}
