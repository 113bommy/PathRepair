#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1000000001;
bool ques;
template <typename T>
void read(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; ((c ^ 48) > 9) && c != '?'; c = getchar())
    if (c == '-') neg = true;
  if (c == '?') ques = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
int n, k, a[N];
bool u[2 * N];
int first(int l, int r, int k) {
  int ans = -k / 2;
  if (ans <= l) ans = l + 1;
  if (ans + k > r) ans = r - k;
  return ans;
}
int main() {
  read(n);
  read(k);
  for (int i = 0, i_end = n; i < i_end; ++i) {
    ques = false;
    read(a[i]);
    if (ques) u[i] = true;
  }
  for (int i = 0, i_end = k; i < i_end; ++i) {
    int last = i - k;
    for (int j = i;; j += k)
      if (!u[j]) {
        int len = (j - last - k) / k, l, r;
        if (len == 0) {
          last = j;
          if (j >= n) break;
          continue;
        }
        if (last < 0)
          l = -INF;
        else
          l = a[last];
        if (j >= n)
          r = INF;
        else
          r = a[j];
        a[last + k] = first(l, r, len);
        for (int ii = last + 2 * k; ii < j; ii += k) a[ii] = a[ii - k] + 1;
        last = j;
        if (j >= n) break;
      }
  }
  for (int i = k, i_end = n; i < i_end; ++i)
    if (a[i] <= a[i - k]) return puts("Incorrect sequence"), 0;
  ;
  for (int i = 0, i_end = n; i < i_end; ++i) printf("%d ", a[i]);
  puts("");
  return 0;
}
