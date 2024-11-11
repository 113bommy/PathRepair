#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int A[1000005];
int B[1000005];
int T[1000005];
int S[1000005];
ll inverse(int s, int e) {
  if (s == e) {
    T[s] = A[s];
    return 0;
  }
  int m = (s + e) / 2;
  ll ans = inverse(s, m) + inverse(m + 1, e);
  for (int i = s; i <= e; i++) {
    S[i] = T[i];
  }
  int i = s, j = m + 1, k = s;
  while (k <= e) {
    if (j > e || (i <= m && S[i] <= S[j]))
      T[k++] = S[i++];
    else
      T[k++] = S[j++], ans += m - i + 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= m; i++) cin >> B[i];
    sort(B + 1, B + m + 1);
    priority_queue<int> pq;
    ll mx = inverse(1, n);
    for (int i = 1; i <= n; i++) {
      int x = lower_bound(B + 1, B + m + 1, A[i]) - B - 1;
      int y = upper_bound(B + 1, B + m + 1, A[i]) - B - 1;
      pq.push(x);
      pq.push(y);
      pq.pop();
      mx += x;
    }
    while (!pq.empty()) {
      mx -= pq.top();
      pq.pop();
    }
    cout << mx << '\n';
  }
  return 0;
}
