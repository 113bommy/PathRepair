#include <bits/stdc++.h>
using namespace std;
long long n, arr[100003], pre[100003], suf[100003];
int bitidx;
bool cmp(long long a, long long b) {
  return ((a >> bitidx) & 1) < ((b >> bitidx) & 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  pre[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pre[i + 1] = pre[i] ^ arr[i];
  }
  suf[0] = 0;
  for (int i = 0; i < n; i++) suf[i + 1] = suf[i] ^ arr[n - i - 1];
  sort(suf, suf + n + 1);
  long long mx = 0;
  for (int k = 0; k <= n; k += 1) {
    int st = 0, en = n;
    for (int i = 40; i >= 0; i -= 1) {
      int bit = (pre[k] >> i) & 1;
      bitidx = i;
      int pos = lower_bound(suf + st, suf + en + 1, (1LL << i), cmp) - suf;
      if (pos > en) continue;
      if (!bit)
        st = pos;
      else
        en = pos - 1;
    }
    mx = max(mx, pre[k] ^ suf[st]);
  }
  cout << mx;
  return 0;
}
