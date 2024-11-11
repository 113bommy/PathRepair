#include <bits/stdc++.h>
using namespace std;
struct F {
  int a, b, h;
  void read() { scanf("%d %d %d", &a, &b, &h); }
};
bool cmp(const F& a, const F& b) {
  if (a.b != b.b) {
    return a.b < b.b;
  }
  if (a.a != b.a) {
    return a.a < b.a;
  }
  return a.h < b.h;
}
vector<long long> t;
int n_;
void init(int nn) {
  n_ = nn;
  t.assign(n_, 0);
}
long long getmax(long long r) {
  long long result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    result = max(result, t[r]);
  }
  return result;
}
void update(int i, long long new_val) {
  for (; i < n_; i = (i | (i + 1))) {
    t[i] = max(t[i], new_val);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<F> a(n);
  vector<int> aa(n);
  for (int i = 0; i < n; ++i) {
    a[i].read();
    aa[i] = a[i].a;
  }
  sort(a.rbegin(), a.rend(), cmp);
  sort(aa.begin(), aa.end());
  aa.erase(unique(aa.begin(), aa.end()), aa.end());
  init(aa.size() + 5);
  vector<long long> dp(1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int pos =
        int(upper_bound(aa.begin(), aa.end(), a[i - 1].b) - aa.begin()) - 1;
    long long rly = getmax(pos);
    dp[i] = max(rly, 0LL) + a[i - 1].h;
    ans = max(ans, dp[i]);
    pos = int(lower_bound(aa.begin(), aa.end(), a[i - 1].a) - aa.begin());
    update(pos, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
