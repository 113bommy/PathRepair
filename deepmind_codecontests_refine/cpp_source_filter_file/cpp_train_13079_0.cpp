#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000555;
long long a[maxn * 2];
int main() {
  long long n;
  int k, pos = 0, tot = 0;
  cin >> n >> k;
  while (n) {
    if (n & 1) a[maxn + pos]++, tot++;
    n >>= 1;
    pos++;
  }
  if (tot > k) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 2 * maxn - 1; i > (0); --i) {
    if (!a[i]) continue;
    if (tot + a[i] > k) continue;
    int can_chg = min((k - tot) * 1LL, a[i]);
    tot = tot + can_chg;
    a[i - 1] += 2 * can_chg;
    a[i] -= can_chg;
  }
  int left = k - tot, min_pos;
  for (int i = 0; i < (maxn * 2); ++i)
    if (a[i]) {
      min_pos = i;
      break;
    }
  cout << "Yes" << endl;
  vector<int> ans;
  for (int i = 2 * maxn - 1; i > (0); --i) {
    for (int j = 0; j < (a[i]); ++j) ans.push_back(i - maxn);
  }
  for (int i = 0; i < ((int)ans.size() - 1); ++i) printf("%d ", ans[i]);
  if (!left) {
    printf("%d\n", ans.back());
  } else {
    int kk = 1;
    while (left > 0) {
      left--;
      printf("%d ", ans.back() - kk);
      kk++;
    }
    printf("%d\n", ans.back() - kk + 1);
  }
}
