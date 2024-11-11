#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int lp[MAX];
int arr[MAX];
map<int, int> mp;
vector<pair<int, int> > vec;
void pre() {
  for (int i = 2; i < MAX; i++) {
    if (!lp[i]) {
      for (int j = i; j < MAX; j += i) {
        if (!lp[j]) {
          lp[j] = i;
        }
      }
    }
  }
}
void fac(int num) {
  while (num > 1) {
    int k = lp[num];
    while (num % k == 0) {
      num /= k;
    }
    mp[k]++;
  }
}
int main() {
  pre();
  int n;
  long long x, y;
  scanf("%d %lld %lld", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    fac(arr[i]);
  }
  vec.push_back(make_pair(n, 2));
  for (auto p : mp) {
    vec.push_back(make_pair(p.second, p.first));
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  long long ans = -1;
  long long u = x;
  for (int i = 0; i < min(5, (int)vec.size()); i++) {
    int x = vec[i].second;
    long long tmp = 0;
    for (int i = 1; i <= n; i++) {
      long long val = (((ceil((double)arr[i] / x)) * x) - arr[i]) * 1ll * y;
      val = min(val, 1ll * u);
      tmp += val;
    }
    if (ans == -1) {
      ans = tmp;
    } else {
      ans = min(ans, tmp);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
