#include <bits/stdc++.h>
using namespace std;
void solve(int cnum) {
  int64_t ans = 0;
  int64_t ans2 = 0;
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  vector<int> ways_to_choose(1000001);
  vector<int> prefsums = ways_to_choose;
  for (int i = A; i <= B; ++i) {
    ways_to_choose[i + B]++;
    ways_to_choose[i + C + 1]--;
  }
  for (int i = 1; i < ways_to_choose.size(); ++i)
    ways_to_choose[i] += ways_to_choose[i - 1];
  for (int i = 1; i < prefsums.size(); ++i)
    prefsums[i] = prefsums[i - 1] + ways_to_choose[i];
  for (int i = C; i <= D; ++i) {
    ans2 += prefsums.back() - prefsums[i];
  }
  cout << ans2 << "\n";
}
int main() {
  int t;
  int cnum = 1;
  for (t = 1; t--; solve(cnum), cnum++)
    ;
  return 0;
}
