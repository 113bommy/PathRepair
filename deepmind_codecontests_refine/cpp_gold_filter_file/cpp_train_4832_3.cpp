#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
};
long long MOD = 1000000007;
long long _MOD = 1000000009;
double EPS = 1e-10;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> sum(2000001);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum[a]++;
  }
  for (int x = 1; x <= 2000000; x++) sum[x] += sum[x - 1];
  for (int d = 1000000;; d--) {
    int cnt = 0;
    for (int x = d; x <= 1000000; x += d)
      cnt += sum[x + min(d - 1, k)] - sum[x - 1];
    if (cnt >= n) {
      cout << d << endl;
      return 0;
    }
  }
}
