#include <bits/stdc++.h>
using namespace std;
const int maxn = 123;
int v[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, S;
  cin >> N >> S;
  v[0] = 0, v[N + 1] = 1e8;
  for (int i = 1; i <= N; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = a * 60 + b;
  }
  if (v[1] >= S + 1) {
    return 0 * puts("0 0");
  }
  for (int i = 1; i <= N; i++) {
    if (v[i + 1] - v[i] > 2 * S + 1) {
      return 0 * printf("%d %d\n", (v[i] + S + 1) / 60, (v[i] + S + 1) % 60);
    }
  }
}
