#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long c[maxn];
vector<long long> method;
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &c[i]);
  }
  for (long long k = 1; k <= 1e18; k *= 2) {
    int now = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i] % k == 0 && (c[i] / k) % 2 == 1) {
        ++now;
      }
    }
    if (now > ans) {
      ans = now;
      method.clear();
      for (int i = 1; i <= n; i++) {
        if (c[i] % k == 0 && (c[i] / k) % 2 == 1) {
        } else {
          method.push_back(c[i]);
        }
      }
    }
  }
  cout << (int)method.size() << endl;
  for (auto k : method) {
    printf("%d ", k);
  }
}
