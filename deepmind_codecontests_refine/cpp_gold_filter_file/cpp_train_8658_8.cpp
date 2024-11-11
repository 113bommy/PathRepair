#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 1;
const int INF = 2e9 + 1;
const int MOD = (1e9 + 7);
void bye() {
  cout << '\n';
  exit(0);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, l, r;
  cin >> n >> l >> r;
  int answer = 0;
  int cur = 1;
  for (int i = 0; i < l; i++) {
    answer += cur;
    cur *= 2;
  }
  cout << answer + n - l << '\n';
  answer = 0;
  cur = 1;
  for (int i = 0; i < r; i++) {
    answer += cur;
    cur *= 2;
  }
  cout << answer + (n - r) * cur / 2;
  bye();
}
