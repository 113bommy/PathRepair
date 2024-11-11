#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100005;
unsigned long long F[N], H[N];
long long in[N];
int n;
unsigned long long hs = 3797;
unsigned long long seg(int x, int y) { return H[y] - F[y - x + 1] * H[x - 1]; }
int main() {
  F[0] = 1;
  for (int i = 1; i < N; i++) F[i] = F[i - 1] * hs;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> in[i];
  H[0] = 0;
  for (int i = 1; i <= n + 1; i++) H[i] = H[i - 1] * hs + in[i];
  map<int, int> pre;
  priority_queue<pair<int, int>> Q;
  for (int i = 1; i <= n; i++) {
    int x = pre[in[i]];
    if (x) {
      int len = i - x;
      if (seg(x, i - 1) == seg(i, i + len - 1)) {
        Q.push(make_pair(len, x));
      }
    }
    pre[in[i]] = i;
  }
  int done = 0;
  while (!Q.empty()) {
    pair<int, int> P = Q.top();
    Q.pop();
    if (done < P.second) {
      done = P.second + P.first - 1;
    }
  }
  cout << n - done << "\n";
  for (int i = done + 1; i <= n; i++) cout << in[i] << " ";
}
