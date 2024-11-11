#include <bits/stdc++.h>
using namespace std;
namespace p231ATeam {
void solve(int test_num) {
  int probs, ans = 0, a, b, c;
  scanf("%d", &probs);
  for (int i = 0; i < probs; i++) {
    scanf("%d %d %d", &a, &b, &c);
    ans += a + b + c >= 2;
  }
  printf("%d\n", ans);
}
void solve() { solve(1); }
}  // namespace p231ATeam
int main() {
  p231ATeam::solve();
  return 0;
}
