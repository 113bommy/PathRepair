#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int in(register T& num) {
  register char c = 0;
  num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  num = n ? -num : num;
  return 1;
}
class BerserkAndFireball {
 public:
  int n, m;
  long long x, k, y;
  int araA[2 * 100002];
  int araB[2 * 100002];
  BerserkAndFireball() { input(); }
  void input() {
    in(n), in(m);
    in(x), in(k), in(y);
    for (int i = 0; i < n; i++) {
      in(araA[i]);
      index[araA[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) in(araB[i]);
  }
  int maxInRange(int l, int r) {
    int mx = -1 << 30;
    for (int i = l + 1; i < r; i++) mx = max(mx, araA[i]);
    return mx;
  }
  long long solution() {
    long long cost = 0;
    int lastPos = -1;
    for (int i = 0; i < m; i++) {
      int curPos = index[araB[i]] - 1;
      if (curPos == -1 || curPos < lastPos) return -1;
      int mxInPair = i > 0 ? max(araB[i], araB[i - 1]) : araA[i];
      long long tmpCost = _calculate(lastPos, curPos, mxInPair);
      if (tmpCost == -1) return -1;
      cost += tmpCost;
      lastPos = curPos;
    }
    long long tmpCost = _calculate(lastPos, n, araB[m - 1]);
    if (tmpCost == -1) return -1;
    return cost + tmpCost;
  }
  long long _calculate(int lastPos, int curPos, int mxInPair) {
    long long costA, costB;
    int mxVal = maxInRange(lastPos, curPos);
    if (mxInPair < mxVal) {
      if ((curPos - lastPos - 1) < k) return -1;
      costA =
          ((curPos - lastPos - 1) / k) * x + ((curPos - lastPos - 1) % k) * y;
      costB = k * x + (curPos - lastPos - 1 - k) * y;
    } else {
      costA =
          ((curPos - lastPos - 1) / k) * x + ((curPos - lastPos - 1) % k) * y;
      costB = (curPos - lastPos - 1) * y;
    }
    return min(costA, costB);
  }

 private:
  map<int, int> index;
};
int main() {
  auto solve = BerserkAndFireball();
  cout << solve.solution();
  return 0;
}
