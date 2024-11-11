#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF = ~0ULL;
const int MAXP = 16;
int prime[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n;
unsigned long long ans;
void dfs(int dept, unsigned long long tmp, int num, int pre) {
  if (num > n) {
    return;
  }
  if (num == n && ans > tmp) {
    ans = tmp;
  }
  for (int i = 1; i <= pre; i++) {
    if (ans / prime[dept] < tmp) {
      break;
    }
    dfs(dept + 1, tmp *= prime[dept], num * (i + 1), i);
  }
}
int main() {
  while (cin >> n) {
    ans = INF;
    dfs(0, 1, 1, 64);
    cout << ans << endl;
  }
  return 0;
}
