#include <bits/stdc++.h>
using namespace std;
const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 5e5 + 5;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() { puts("Yes"); }
void NO() {
  puts("NO");
  exit(0);
}
void No() { puts("No"); }
void one() {
  puts("-1");
  exit(0);
}
int n, k, m;
int val[maxn];
vector<pair<int, int> > st;
void solve() {
  scanf("%d", &(n)), scanf("%d", &(k)), scanf("%d", &(m));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &(val[i]));
    if (st.size() == 0) {
      st.push_back(make_pair(val[i], 1));
    } else {
      auto t = st.back();
      if (val[i] == t.first) {
        t.second++;
      } else {
        st.push_back(make_pair(val[i], 1));
      }
    }
    if (st.back().second == k) {
      st.pop_back();
    }
  }
  if (st.size() == 0) {
    puts("0");
    return;
  }
  long long ans = 0;
  for (int i = 0; i < st.size(); i++) {
    ans += st[i].second;
  }
  ans *= m;
  int le = 0;
  int ri = st.size() - 1;
  while (le < ri) {
    if (st[le].first != st[ri].first) {
      printf("%lld\n", ans);
      return;
    }
    if (st[le].second + st[ri].second < k) {
      printf("%lld\n", ans);
      return;
    }
    ans -= 1LL * k * (m - 1);
    if (st[le].second + st[ri].second > k) {
      printf("%lld\n", ans);
      return;
    }
    le++;
    ri--;
  }
  if (le == ri) {
    long long tmp = 1LL * st[le].second * m;
    long long rem = tmp % k;
    ans -= tmp - rem;
    if (rem == 0) ans = 0;
    printf("%lld\n", ans);
  } else {
    puts("0");
  }
}
int main() {
  solve();
  return 0;
}
