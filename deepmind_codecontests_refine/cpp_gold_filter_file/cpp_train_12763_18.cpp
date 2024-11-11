#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 20;
int perm[MAX], change[MAX];
void solve(int test_num) {
  (void)test_num;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", perm + i);
    --perm[i];
  }
  int leq = 0;
  long long sum = 0;
  memset(change, 0, sizeof(change));
  for (int i = 0; i < n; ++i) {
    sum += abs(perm[i] - i);
    if (perm[i] > i)
      ++change[perm[i] - i];
    else {
      ++leq;
      ++change[n - (i - perm[i])];
    }
  }
  pair<long long, int> res(sum, 0);
  for (int k = 1; k < n; ++k) {
    sum += leq - (n - leq);
    leq += change[k];
    sum -= abs(perm[n - k] - n);
    sum += abs(perm[n - k]);
    --leq;
    res = min(res, {sum, k});
  }
  cout << res.first << " " << res.second << endl;
}
void init() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  init();
  int tests = 1;
  for (int test = 1; test <= tests; ++test) {
    solve(test);
  }
  return 0;
}
