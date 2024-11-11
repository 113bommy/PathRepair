#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int tank[MAXN];
int N;
int solve(int BG) {
  int id = BG + N - 1, ret = 1;
  while (id - tank[id] > BG) {
    ++ret;
    int cur = -1, preMost = N + 100;
    for (int i = 1; i <= tank[id]; ++i) {
      if (id - i - tank[id - i] < preMost) {
        preMost = id - i - tank[id - i];
        cur = id - i;
      }
    }
    id = cur;
  }
  return ret;
}
int main() {
  while (cin >> N) {
    for (int i = 0; i < N; ++i) {
      cin >> tank[i];
      tank[i + N] = tank[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += solve(i);
    }
    cout << ans << endl;
  }
  return 0;
}
