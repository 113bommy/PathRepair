#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxN = 1009;
int N, t1, t2, k;
pair<int, int> ans[maxN];
void enter() { cin >> N >> t1 >> t2 >> k; }
void process() {
  int a, b;
  for (int i = 1; i <= N; i++) {
    cin >> a >> b;
    ans[i] = {-max(a * t1 * (100 - k) + b * t2 * 100,
                   b * t1 * (100 - k) + a * t1 * 100),
              i};
  }
  sort(ans + 1, ans + N + 1);
  for (int i = 1; i <= N; i++)
    printf("%d %.2f\n", ans[i].second, -0.01 * (double)ans[i].first);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process();
  return 0;
}
