#include <bits/stdc++.h>
void calc_impl(std::vector<int>& v, int k, double& res) {
  if (k == 0) {
    int s = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (v[i] > v[j]) {
          s += 1;
        }
      }
    }
    res += s;
    return;
  }
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i; j < v.size(); ++j) {
      std::reverse(v.begin() + i, v.begin() + j + 1);
      calc_impl(v, k - 1, res);
      std::reverse(v.begin() + i, v.begin() + j + 1);
    }
  }
}
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    v.push_back(k);
  }
  if (n == 1) {
    std::cout << 0.0 << "\n";
    return 0;
  }
  double p = 1.0;
  for (int i = 0; i < k; ++i) {
    p *= (1.0 / (v.size() * (v.size() - 1)));
  }
  double res = 0.0;
  calc_impl(v, k, res);
  std::cout.precision(15);
  std::cout << p * res << "\n";
  return 0;
}
