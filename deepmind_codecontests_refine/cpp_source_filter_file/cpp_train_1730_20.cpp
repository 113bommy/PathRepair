#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
int cnt[N];
long long sum[N];
long long ans = 1e18;
int n, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    int z;
    cin >> z;
    cnt[z]++;
    sum[z] += z;
  }
  for (int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  for (int i = 2; i < N; i++) {
    long long s = 0;
    for (int j = i; j < N; j += i) {
      long long var = cnt[j] - cnt[j - i];
      long long a = j - min(i, x / y + 1);
      long long b = cnt[j] - cnt[a];
      s += (b * j - (sum[j] - sum[a])) * y + x * (var - b);
    }
    ans = min(ans, s);
  }
  cout << ans;
}
