#include <bits/stdc++.h>
using namespace std;
vector<int64_t> divisors(int64_t n) {
  vector<int64_t> divisors;
  for (int64_t i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (n / i != i) {
        divisors.push_back(n / i);
      }
    }
  }
  return divisors;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    int n;
    cin >> n;
    int64_t input[n + 1];
    for (int i = 1; i <= n; ++i) cin >> input[i];
    sort(input + 1, input + n + 1);
    vector<int64_t> res = divisors(input[1] * input[n]);
    if ((int)res.size() - 2 != n) {
      cout << "-1\n";
      continue;
    }
    sort(res.begin(), res.end());
    bool yes = true;
    for (int i = 1; i <= n; ++i) {
      if (res[i] != input[i + 1]) {
        yes = false;
        break;
      }
    }
    if (!yes) {
      cout << "-1\n";
      continue;
    }
    cout << input[1] * input[n] << '\n';
  }
}
