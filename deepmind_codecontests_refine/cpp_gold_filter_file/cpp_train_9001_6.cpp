#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
long long n, q, arr[MAXN], dp[MAXN], psum[MAXN];
long long sum(int v, int u) {
  if (v <= u) {
    return psum[u] - (v ? psum[v - 1] : 0);
  }
  return psum[n - 1] - (v ? psum[v - 1] : 0) + psum[u];
}
void base(long long v) {
  int pos = n - 2, now = n - 1;
  for (; ~now; now--) {
    while (sum(now, pos) > v) {
      pos = (pos + n - 1) % n;
      if (pos == now) {
        break;
      }
    }
    dp[now] = pos;
  }
  return;
}
int finder(int st) {
  int ans = 0, now = st;
  long long s = 0;
  while (s < psum[n - 1]) {
    ans++;
    s += sum(now, dp[now]);
    now = (dp[now] + 1) % n;
  }
  return ans;
}
int answer() {
  int mini = 1e9, id = -1, ans = 1e9;
  for (int i = 0; i < n; i++) {
    if ((dp[i] >= i ? dp[i] - i + 1 : dp[i] + n - i + 1) < mini) {
      mini = (dp[i] >= i ? dp[i] - i + 1 : dp[i] + n - i + 1);
      id = i;
    }
  }
  for (int i = 0; i <= mini; i++) {
    ans = min(ans, finder((id + i) % n));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i) {
      psum[i] = psum[i - 1];
    }
    psum[i] += arr[i];
  }
  while (q--) {
    long long k;
    cin >> k;
    base(k);
    cout << answer() << endl;
  }
  return 0;
}
