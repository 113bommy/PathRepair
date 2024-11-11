#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, k;
char str[N];
int tmp[N], idx;
int distance(int l, int r, int pos) {
  return max(abs(l - tmp[pos]), abs(r - tmp[pos]));
}
int cal(int l, int r, int cnt) {
  int pos1 = lower_bound(tmp + cnt, tmp + idx, (l + r) / 2) - tmp;
  int pos2 = pos1 - 1;
  if (tmp[pos2] < l) return distance(l, r, pos1);
  return min(distance(l, r, pos1), distance(l, r, pos2));
}
int main() {
  while (cin >> n >> k) {
    scanf("%s", str);
    memset(tmp, 0, sizeof(tmp));
    idx = 0;
    int l = 0, r = 0;
    int i = 0;
    while (str[i] != '0') {
      i++;
      l++;
      r++;
    }
    l = r = i;
    tmp[idx++] = l;
    i++;
    while (idx < k + 1) {
      if (str[i] == '0') {
        r = i;
        tmp[idx++] = r;
      }
      i++;
    }
    int ans = N, cnt = 0;
    while (r < n) {
      ans = min(ans, cal(l, r, cnt));
      l = tmp[++cnt];
      r++;
      while (str[r] != '0' && r < n) {
        r++;
      }
      tmp[idx++] = r;
    }
    cout << ans << endl;
  }
  return 0;
}
