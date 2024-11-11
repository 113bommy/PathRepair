#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
const int MOD = 100000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_WN = 3000010;
long long deg[MAX_WN];
int N;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    deg[x]++;
  }
  for (int i = 0; i <= MAX_WN - 10; i++) {
    deg[i + 1] += deg[i] / 2LL;
    deg[i] = deg[i] % 2LL;
  }
  int ans = 0;
  for (int i = 0; i < MAX_WN; i++) {
    if (deg[i] >= 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
