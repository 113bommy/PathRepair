#include <bits/stdc++.h>
long long int &getNextX(long long int &x) {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void init_ab(std::vector<long long int> &a, std::vector<long long int> &b,
             long long int n, long long int d, long long int x) {
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    std::swap(a[i], a[getNextX(x) % (i + 1)]);
  }
  for (int i = 0; i < n; ++i) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    std::swap(b[i], b[getNextX(x) % (i + 1)]);
  }
}
int main() {
  long long int n, d, x;
  std::cin >> n >> d >> x;
  std::vector<long long int> a, b;
  a.reserve(100001);
  b.reserve(100001);
  init_ab(a, b, n, d, x);
  std::vector<long long int> a_lookup(n);
  for (int i = 0; i < n; ++i) {
    a_lookup[a[i] - 1] = i;
  }
  std::vector<long long int> b_next_one(n, 0);
  int next_one_index = std::numeric_limits<int>::max();
  for (int i = n - 1; i >= 0; --i) {
    b_next_one[i] = next_one_index;
    if (b[i] == 1) next_one_index = i;
  }
  for (int c_i = 0; c_i < n; ++c_i) {
    for (int n_to_check = n; n_to_check > n - 1000 && n_to_check > 0;
         --n_to_check) {
      int n_to_check_loc = a_lookup[n_to_check - 1];
      if (n_to_check_loc > c_i) continue;
      if (b[n - 1 - n_to_check_loc] == 1) {
        std::cout << n_to_check << "\n";
        goto c_i_done;
      }
    }
    {
      long long int res = 0;
      if (b[0] == 1) res = a[c_i];
      for (int j = 0; j < c_i; j = b_next_one[j]) {
        if (b[j] == 1) {
          res = std::max(res, a[c_i - j]);
        }
      }
      std::cout << res << "\n";
    }
  c_i_done:;
  }
  return 0;
}
