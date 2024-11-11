#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int tc = nxt();
  while (tc--) {
    int n = nxt();
    long long int w;
    cin >> w;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> order(n);
    iota((order).begin(), (order).end(), 0);
    sort((order).begin(), (order).end(),
         [&](int i, int j) { return a[i] < a[j]; });
    long long int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (a[order[0]] > w || sum < (w + 1) / 2) {
      puts("-1");
      continue;
    }
    sum = 0;
    vector<int> ans;
    for (int i : order) {
      if (sum + a[i] >= (w + 1) / 2) {
        if (sum + a[i] > w) {
          if (a[i] > w) {
            puts("-1");
          } else
            printf("1\n%d\n", i + 1);
          goto end;
        } else {
          ans.push_back(i);
          printf("%d\n", ans.size());
          for (int j : ans) printf("%d ", j + 1);
          printf("\n");
          goto end;
        }
      } else {
        sum += a[i];
        ans.push_back(i);
      }
    }
  end:;
  }
  return 0;
}
