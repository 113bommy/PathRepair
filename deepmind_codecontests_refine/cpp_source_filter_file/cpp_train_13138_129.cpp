#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
template <int MOD>
struct str_hash {
  static int P;
  int n;
  string second;
  vector<long long> h, power;
  str_hash(string s_) : n(s_.size()), second(s_), h(n), power(n) {
    power[0] = 1;
    for (int i = 1; i < n; i++) power[i] = power[i - 1] * P % MOD;
    h[0] = second[0];
    for (int i = 1; i < n; i++) h[i] = (h[i - 1] * P + second[i]) % MOD;
  }
  long long operator()(int i, int j) {
    if (!i) return h[j];
    return (h[j] - h[i - 1] * power[j - i + 1] % MOD + MOD) % MOD;
  }
};
template <int MOD>
int str_hash<MOD>::P = uniform(27, MOD - 1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string second;
  cin >> second;
  str_hash<1000005> h(second);
  int n = second.size();
  long long melhor = 0;
  for (int I = 1; I < n; I++) {
    long long low = 0, high = n - I;
    while (low + 1 < high) {
      long long mid = (low + high) / 2;
      if (h(0, mid - 1) == h(I, I + mid - 1)) {
        low = mid;
      } else {
        high = mid;
      }
      melhor = max(melhor, low);
    }
  }
  for (long long I = melhor; I > 0; I--) {
    if (h(0, I - 1) != h(n - I, n - 1)) {
      continue;
    }
    cout << second.substr(0, I) << '\n';
    return 0;
  }
  cout << "Just a legend" << '\n';
  return 0;
}
