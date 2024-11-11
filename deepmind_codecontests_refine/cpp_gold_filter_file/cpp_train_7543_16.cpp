#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int odd_cnt = 0, odd = -1, odd_ok;
int n, a[100005];
bool ck(int i) {
  if (a[i] != a[n - 1 - i]) return 0;
  if (odd != -1 && i == n / 2 && a[i] != odd) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i), cnt[a[i]]++;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    if (it->second & 1) odd_cnt++, odd = it->first;
    it->second /= 2;
  }
  if (odd_cnt > 1) {
    printf("0");
    return 0;
  }
  odd_ok = (odd == -1 ? true : a[n / 2] == odd);
  int s, e;
  for (s = 0; s <= n / 2 - 1;) {
    if (cnt[a[s]] == 0)
      break;
    else
      cnt[a[s]]--, s++;
  }
  for (int i = 0; i < n; ++i) cnt[a[i]] = 0;
  for (int i = 0; i < n; ++i) cnt[a[i]]++;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) it->second /= 2;
  for (e = n - 1; e >= (n + 1) / 2;) {
    if (cnt[a[e]] == 0)
      break;
    else
      cnt[a[e]]--, e--;
  }
  int out_same = 0, in_same = 0;
  for (int i = 0; i < n / 2; ++i)
    if (ck(i))
      out_same++;
    else
      break;
  for (int i = n / 2 - 1; i >= 0; --i)
    if (ck(i))
      in_same++;
    else
      break;
  long long ans = 0;
  for (int i = 0; i <= n / 2 - 1; ++i) {
    if (s < i) break;
    int end = n - 1;
    if (e == (n + 1) / 2 - 1 && odd_ok && i <= out_same)
      end = max(i, n / 2 - 1 - in_same);
    else if (out_same >= i)
      end = e;
    else
      end = n - 1 - out_same;
    ans += n - end;
  }
  if (odd != -1 && s == n / 2) {
    ans += n - (n - 1 - out_same);
  }
  for (int i = (n + 1) / 2; i < n; ++i)
    if (s == n / 2) {
      if (i - 1 - ((n + 1) / 2 - 1) > in_same) break;
      ans += n - max(i, n - 1 - out_same);
    }
  cout << ans;
}
