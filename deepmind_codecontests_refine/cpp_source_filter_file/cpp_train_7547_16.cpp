#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  int a[n];
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
  }
  --n;
  for (int i = 0; i < (int)(n); ++i) {
    a[i] = abs(a[i + 1] - a[i]);
  }
  int cntLeft[n], cntRight[n];
  for (int turn = 0; turn < (int)(2); ++turn) {
    int prev = -1;
    int j = 0;
    int delta = turn;
    vector<int> stack;
    for (int i = 0; i < (int)(n); ++i) {
      int x = a[i];
      if (x - prev < delta) {
        stack.clear();
        j = i;
      } else {
        while (j - 1 >= 0 && x - a[j - 1] >= delta) {
          stack.push_back(a[j]);
          --j;
        }
        while (!stack.empty() && x - stack.back() < delta) {
          stack.pop_back();
          ++j;
        }
      }
      (turn ? cntRight[n - 1 - i] : cntLeft[i]) = i - j;
      prev = x;
    }
    reverse(a, a + n);
  }
  for (int t = 0; t < (int)(q); ++t) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    long long res = 0;
    for (int i = l; i <= (int)(r - 1); ++i) {
      int left = min(i - l, cntLeft[i]);
      int right = min(r - 1 - i, cntRight[i]);
      res += 1LL * a[i] * (left + 1) * (right + 1);
    }
    printf("%I64\n", res);
  }
  return 0;
}
