#include <bits/stdc++.h>
const int MAX = 300010;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const long double PI = acosl(-1.0);
using namespace std;
int a[101], b[101], v[101];
bool side[101];
int hl, hr, n;
long double H = 1e2, W = 1e5;
int resp = 0;
bool visited[101];
void solve(int num, int ini) {
  memset(visited, false, sizeof(visited));
  int sum = 0;
  long double k = ((num & 1 ? H - hr : hr) - hl + num * (ini ? 1 : -1) * H) / W;
  for (int i = ini; i < ini + num; i++) {
    long double pos = ((ini ? 1 : -1) * H * i - hl) / k;
    for (int j = 0; j < n; j++) {
      if (side[j] == (i % 2) and a[j] <= pos and pos <= b[j]) {
        if (visited[j]) return;
        sum += v[j];
        visited[j] = true;
        break;
      }
      if (j == n - 1) return;
    }
  }
  resp = max(resp, sum);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> hl >> hr >> n;
  int V, A, B;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> V >> c >> A >> B;
    side[i] = (c == 'T');
    a[i] = A;
    b[i] = B;
    v[i] = V;
  }
  for (int i = 1; i <= n; i++) {
    solve(i, 0);
    solve(i, 1);
  }
  cout << resp << '\n';
  return 0;
}
