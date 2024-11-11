#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, r, c;
string str[maxn];
int len[maxn];
int sum[maxn + 1];
int jump[maxn], res[maxn];
void Tran(const int *a, const int *b, int *c) {
  static int tmp[maxn];
  for (int i = 0; i < n; ++i) {
    tmp[i] = a[i] == n ? n : b[a[i]];
  }
  copy(tmp, tmp + n, c);
}
int main(void) {
  scanf("%d%d%d", &n, &r, &c);
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
    len[i] = str[i].length();
    sum[i + 1] = sum[i] + len[i];
  }
  for (int i = 0; i < n; ++i) {
    int low = i, high = n + 1;
    while (high - low > 1) {
      int mid = low + high >> 1;
      if (sum[mid] - sum[i] + (mid - i - 1) <= c) {
        low = mid;
      } else {
        high = mid;
      }
    }
    jump[i] = low;
  }
  for (int i = 0; i < n; ++i) {
    res[i] = i;
  }
  for (int y = r; y; y >>= 1) {
    if (y & 1) Tran(res, jump, res);
    Tran(jump, jump, jump);
  }
  int best = 0;
  for (int i = 1; i < n; ++i) {
    if (res[i] - i > res[best] - best) {
      best = i;
    }
  }
  for (int i = 0; i < r; ++i) {
    int rest = c + 1;
    while (best < n && len[best] < rest) {
      if (rest < c + 1) putchar(' ');
      rest -= len[best] + 1;
      printf("%s", str[best].c_str());
      ++best;
    }
    putchar('\n');
  }
  return 0;
}
