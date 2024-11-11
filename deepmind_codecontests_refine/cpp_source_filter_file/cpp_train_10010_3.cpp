#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const long long INF64 = 1e18;
const int N = 1e5 + 5;
long long LOG[2 * N];
long long sparse[2 * N][20];
long long arr[2 * N];
long long pos[2 * N];
void build() {
  LOG[1] = 0;
  for (int i = 1; i < 2 * N; i++) {
    if (i > 1) LOG[i] = LOG[i / 2] + 1;
    sparse[i][0] = i;
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i < 2 * N && i + (1LL << (j - 1)) < 2 * N; i++) {
      if (arr[sparse[i][j - 1]] > arr[sparse[i + (1LL << (j - 1))][j - 1]])
        sparse[i][j] = sparse[i][j - 1];
      else
        sparse[i][j] = sparse[i + (1LL << (j - 1))][j - 1];
    }
  }
}
long long query(long long a, long long b) {
  long long now = LOG[b - a + 1];
  if (arr[sparse[a][now]] > arr[sparse[b - (1LL << (now) + 1)][now]]) {
    return sparse[a][now];
  }
  return sparse[b - (1LL << now) + 1][now];
}
long long solve(long long a, long long b) {
  if (b < a) return 0;
  long long ret = 0LL;
  long long now = query(a, b);
  if (b - now < now - a) {
    for (int i = now + 1; i <= b; i++) {
      long long cur = arr[now] - arr[i];
      if (1 <= pos[cur] && pos[cur] < now) ret++;
    }
  } else {
    for (int i = 0; i < now; i++) {
      long long cur = arr[now] - arr[i];
      if (now + 1 <= pos[cur] && pos[cur] <= b) ret++;
    }
  }
  ret = ret + solve(a, now - 1);
  ret = ret + solve(now + 1, b);
  return ret;
}
int main() {
  memset((arr), 0, sizeof(arr));
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  build();
  cout << solve(1, n);
  return 0;
}
