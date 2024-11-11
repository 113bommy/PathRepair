#include <bits/stdc++.h>
using namespace std;
struct S {
  long long s, a, b;
  S(long long s, long long a, long long b) : s(s), a(a), b(b) {}
};
vector<S> v1, v2;
bool cmp1(S a, S b) { return abs(a.a - a.b) < abs(b.a - b.b); }
int main() {
  long long N, S, i, s, a, b;
  cin >> N >> S;
  long long ans = 0;
  long long A = 0, B = 0;
  for (i = 1; i <= N; i++) {
    cin >> s >> a >> b;
    if (a > b) {
      ans += a * s;
      A += s;
      v1.push_back({s, a, b});
    } else {
      ans += b * s;
      B += s;
      v2.push_back({s, a, b});
    }
  }
  sort(v1.begin(), v1.end(), cmp1);
  sort(v2.begin(), v2.end(), cmp1);
  long long c = A % S, cc = B % S;
  long long ans1 = ans, ans2 = ans;
  if (A % S == 0 || B % S == 0 || c + cc > S) {
    cout << ans << endl;
    return 0;
  }
  for (auto it : v1) {
    if (it.s >= c) {
      ans1 -= c * (it.a - it.b);
      break;
    }
    ans1 -= it.s * (it.a - it.b);
    c -= it.s;
  }
  for (auto it : v2) {
    if (it.s >= cc) {
      ans2 -= c * (it.b - it.a);
      break;
    }
    ans2 -= it.s * (it.b - it.a);
    cc -= it.s;
  }
  cout << max(ans1, ans2) << endl;
}
