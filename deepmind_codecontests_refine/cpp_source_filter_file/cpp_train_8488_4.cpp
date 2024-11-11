#include <bits/stdc++.h>
using namespace std;
const int max_num_prime = 100000;
const int maxn = 1000000;
const int log_maxn = 20;
const int mod = 1000000007;
bool isprime[maxn + 1], is_fixed[maxn + 1];
int remain[maxn + 1];
int num_prime, prime[max_num_prime + 1];
int root[maxn + 1], last_prime[maxn + 1];
int P[maxn + 1];
int n, A[maxn + 1];
inline int mul(int x, int y) { return x * (long long)y % mod; }
void preprocess(int n) {
  P[0] = P[1] = 1;
  root[1] = 1;
  num_prime = 0;
  for (int i = 2; i <= n; ++i) {
    isprime[i] = true;
    remain[i] = 0;
    P[i] = mul(P[i - 1], i);
  }
  int x;
  for (int i = 2; i <= n; ++i) {
    if (isprime[i]) {
      prime[num_prime++] = i;
      root[i] = i;
      remain[i] = 1;
      last_prime[i] = i;
    }
    for (int j = 0; j < num_prime && i * prime[j] <= n; ++j) {
      x = i * prime[j];
      isprime[x] = false;
      if (i % prime[j] == 0) {
        root[x] = root[i];
        remain[root[x]]++;
        break;
      } else {
        root[x] = root[i] * prime[j];
        last_prime[x] = prime[j];
        remain[root[x]]++;
      }
    }
  }
}
int num_index_factor, num_actual_factor;
int solve() {
  fill(is_fixed, is_fixed + n + 1, false);
  if (A[1] != 0) {
    if (A[1] != 1 && (!isprime[A[1]] || n / A[1] > 1)) {
      return 0;
    }
    is_fixed[A[1]] = true;
  }
  int index_max_prime, actual_max_prime;
  for (int i = 2; i <= n; ++i) {
    if (A[i] == 0) {
      continue;
    }
    --remain[root[A[i]]];
    is_fixed[root[A[i]]] = true;
    if (isprime[i]) {
      if (A[i] == 1) {
        is_fixed[1] = true;
        if (n / i > 1) {
          return 0;
        }
      } else if (!isprime[root[A[i]]] || (n / root[A[i]] != n / i)) {
        return 0;
      }
    } else {
      num_index_factor = 0;
      for (int j = root[i]; j > 1; j /= last_prime[j]) {
        num_index_factor++;
        index_max_prime = last_prime[j];
      }
      num_actual_factor = 0;
      for (int j = root[A[i]]; j > 1; j /= last_prime[j]) {
        num_actual_factor++;
        actual_max_prime = last_prime[j];
      }
      if (num_actual_factor != num_index_factor ||
          n / index_max_prime != n / actual_max_prime) {
        return 0;
      }
      if (n / actual_max_prime < actual_max_prime) {
        is_fixed[actual_max_prime] = true;
        if (A[index_max_prime] == 0) {
          --remain[root[actual_max_prime]];
          A[index_max_prime] = actual_max_prime;
        } else if (root[A[index_max_prime]] != actual_max_prime) {
          return 0;
        }
      }
    }
  }
  int ans = 1;
  int num_equiv_prime = 0;
  int level = 1;
  for (int i = n; i >= 2; --i) {
    if (root[i] != i) {
      continue;
    }
    ans = mul(ans, P[remain[i]]);
    if (isprime[i]) {
      if (n / i != level) {
        ans = mul(ans, P[num_equiv_prime + (level == 1 && !is_fixed[1])]);
        num_equiv_prime = 0;
        level = n / i;
      } else if (!is_fixed[i]) {
        num_equiv_prime++;
      }
    }
  }
  if (num_equiv_prime > 0) {
    ans = mul(ans, P[num_equiv_prime + (level == 1 && !is_fixed[1])]);
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  preprocess(n);
  cout << solve() << endl;
}
