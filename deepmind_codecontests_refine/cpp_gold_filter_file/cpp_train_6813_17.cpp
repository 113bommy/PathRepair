#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
long long N, M, K, P;
long long a[1010][1010];
priority_queue<long long> q1, q2;
long long cnt1[MAXN + 1], cnt2[MAXN + 1];
void solve() {
  cin >> N >> M >> K >> P;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= M; j++) {
      sum += a[i][j];
    }
    q1.push(sum);
  }
  for (int j = 1; j <= M; j++) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
      sum += a[i][j];
    }
    q2.push(sum);
  }
  for (int i = 1; i <= MAXN; i++) {
    long long tmp = q1.top();
    cnt1[i] = cnt1[i - 1] + tmp;
    q1.pop();
    tmp -= P * M;
    q1.push(tmp);
  }
  for (int i = 1; i <= MAXN; i++) {
    long long tmp = q2.top();
    cnt2[i] = cnt2[i - 1] + tmp;
    q2.pop();
    tmp -= P * N;
    q2.push(tmp);
  }
  long long ans = -1e18;
  for (int i = 0; i <= K; i++) {
    ans = max(ans, cnt1[i] + cnt2[K - i] - i * (K - i) * P);
  }
  cout << ans << endl;
}
void Times(int T) {
  while (T--) {
    solve();
  }
}
int main() {
  int T;
  T = 1;
  Times(T);
  return 0;
}
