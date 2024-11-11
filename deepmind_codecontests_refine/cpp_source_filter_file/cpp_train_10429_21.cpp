#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int phi[N], divs[N];
void sieve() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++)
    if (phi[i] == i)
      for (int j = i; j < N; j += i) {
        phi[j] = (phi[j] / i) * (i - 1);
      }
  for (int i = 1; i < N; i++)
    for (int j = 2 * i; j < N; j += i) divs[j]++;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << 2 << endl;
    return 0;
  }
  priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>>
      pq;
  pq.push(pair<int, int>(1, 1));
  long long ans = 0;
  int cnt = 0;
  while (pq.size() && cnt < k + 2) {
    int x = pq.top().second;
    pq.pop();
    cnt++;
    ans += phi[x];
    for (int j = x; j <= n; j += x) {
      divs[j]--;
      if (divs[j] == 0) pq.push(pair<int, int>(phi[j], j));
    }
  }
  cout << ans << endl;
}
