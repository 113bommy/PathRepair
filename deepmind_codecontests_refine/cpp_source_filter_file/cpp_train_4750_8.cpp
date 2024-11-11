#include <bits/stdc++.h>
using namespace std;
int P(int N, vector<int>& stack) {
  if (stack.size() == 1) return N / stack.back();
  int sum = 0;
  int x = stack.back();
  stack.pop_back();
  sum += P(N, stack);
  sum += N / x;
  sum -= P(N / x, stack);
  stack.push_back(x);
  return sum;
}
void prime_factors(int N, vector<int>& all, vector<int>& stack,
                   vector<int>& c_ones, int i = 0, int x = 1) {
  for (; i < all.size() && x * (int64_t)all[i] <= N; i++) {
    stack.push_back(all[i]);
    c_ones[x * all[i]] = P(N, stack);
    prime_factors(N, all, stack, c_ones, i + 1, x * all[i]);
    stack.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int n = N + 1;
  vector<int> factor(n, 0);
  vector<int> primes(n, 0);
  vector<int> count(n, 0);
  vector<int> pred(n, 0);
  vector<int> c_ones(n, 0);
  vector<int> all;
  all.reserve(n);
  for (int i = 2; i < n; i++) {
    if (primes[i]) continue;
    all.push_back(i);
    for (int j = i; j < n; j += i)
      if (!primes[j])
        factor[j] = primes[j] = i;
      else if (primes[j] % i)
        primes[j] *= i;
  }
  for (int i = 2; i < n; i++) count[factor[i]]++;
  for (int i = 2; i < n; i++) pred[i] = pred[i - 1] + count[i];
  vector<int> stack;
  prime_factors(N, all, stack, c_ones);
  int64_t ones = 1;
  for (int i = 0; i < n; i++)
    if (primes[i]) ones += c_ones[primes[i]];
  int64_t threes = 1;
  for (int x : all)
    if (x * 2 > N) threes++;
  threes = (N - threes) * (N - threes) + threes;
  int64_t twos = 1;
  auto rj = all.rbegin(), re = all.rend();
  for (int i : all) {
    int row = 0;
    while (rj != re && *rj * (int64_t)i > N) rj++;
    if (rj != re) row = pred[*rj];
    if (i * (int64_t)i > N) row++;
    twos += count[i] * row;
  }
  int64_t res = 0;
  res += 1 * (ones - N);
  res += 2 * (twos - ones);
  res += 3 * (threes - twos);
  cout << res / 2 << "\n";
  return 0;
}
