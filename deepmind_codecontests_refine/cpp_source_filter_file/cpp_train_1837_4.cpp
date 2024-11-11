#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("no-stack-protector,unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
const int MAGIC = 5000;
long long calc(vector<long long> a, vector<long long> b, int k) {
  int an = (int)a.size();
  int bn = (int)b.size();
  multiset<long long> prods;
  long long top_k = 0;
  long long ans = 0;
  for (int i = 0; i < min(an, MAGIC); i++) {
    for (int j = 0; j < bn; j++) {
      long long prod = 1LL * a[i] * b[j];
      if (prods.size() < k) {
        prods.insert(prod);
        top_k += prod;
      } else {
        if (prod > *prods.begin()) {
          top_k -= *prods.begin();
          prods.erase(prods.begin());
          prods.insert(prod);
          top_k += prod;
        } else {
          break;
        }
      }
      ans = max(ans, top_k);
    }
    ans = max(ans, top_k);
  }
  return ans;
}
int main() {
  int n, m, r, k;
  scanf("%d%d%d%d", &n, &m, &r, &k);
  long double denumerator = (long double)(n - r + 1) * (m - r + 1);
  vector<long long> weight_i;
  for (int i = 1; i <= n; i++) {
    weight_i.push_back(max(0, min(n - r + 1, i) - max(1, i - r + 1) + 1));
  }
  vector<long long> weight_j;
  for (int j = 1; j <= m; j++) {
    weight_j.push_back(max(0, min(m - r + 1, j) - max(1, j - r + 1) + 1));
  }
  sort(weight_i.begin(), weight_i.end());
  reverse(weight_i.begin(), weight_i.end());
  sort(weight_j.begin(), weight_j.end());
  reverse(weight_j.begin(), weight_j.end());
  long long numerator =
      max(calc(weight_i, weight_j, k), calc(weight_j, weight_i, k));
  long double answer = calc(weight_i, weight_j, k) / denumerator;
  cout.precision(20);
  cout << fixed << answer << "\n";
  return 0;
}
