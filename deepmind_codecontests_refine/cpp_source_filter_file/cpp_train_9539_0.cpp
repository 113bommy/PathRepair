#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  int type;
} N[500000];
int main() {
  long long n, a, b, c, d, start, len;
  cin >> n >> a >> b >> c >> d >> start >> len;
  for (int i = 1; i <= n; i++) {
    cin >> N[i].val >> N[i].type;
  }
  long long s = 1, t = 1, sum_st = start, ans = 0;
  long long low = 0;
  N[0].val = -1;
  for (int s = 1; s <= n; s++) {
    while (t <= n && N[t].val - N[s].val <= len) {
      if (N[t].type == 1)
        ans += c;
      else if (N[t].type == 0)
        ans -= d;
      low = min(low, ans);
      t++;
    }
    if (sum_st + low >= 0) {
      cout << N[s - 1].val + 1 << endl;
      return 0;
    }
    if (N[s].type == 1) {
      ans -= c;
      low -= c;
      sum_st += a;
    } else {
      ans += d;
      low += d;
      sum_st -= b;
    }
    if (sum_st < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << N[n - 1].val + 1 << endl;
}
