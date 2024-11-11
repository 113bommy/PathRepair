#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
map<int, int> mp, mp1, mp2;
map<int, int>::iterator it;
struct sw {
  int l, r;
  sw() {}
  sw(int ll, int rr) { l = ll, r = rr; }
} ans[2];
int n;
int num[maxn];
int flag, cou = 0, cou2 = 0, now, key;
unsigned long long res = 0;
bool check(int l, int r) {
  mp1.clear();
  int len1 = r - l + 1, len2 = n - 2 * now - len1;
  if (len2 < len1) {
    if (l == now + 1) {
      r = n - l + 1;
      l = r - len2 + 1;
    } else {
      l = n - r + 1;
      r = l + len2 - 1;
    }
  }
  for (; l <= r; l++) mp1[num[l]]++;
  for (it = mp1.begin(); it != mp1.end(); it++) {
    if (it->second > mp[it->first] / 2) return 0;
  }
  return 1;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    mp[num[i]]++;
  }
  flag = n % 2;
  for (it = mp.begin(); it != mp.end(); it++) {
    if (it->second % 2) cou++, key = it->first;
    if (cou > flag) break;
  }
  if (cou > flag) {
    printf("0\n");
    return 0;
  }
  for (int s = 1, e = n; s < e; s++, e--) {
    if (num[s] != num[e]) {
      now = s - 1;
      int l = 1, r = e - s;
      for (int i = (n + 1) / 2, j = (n + 2) / 2; 1; i--, j++)
        if (num[i] != num[j] || (i == (n + 1) / 2 && num[i] != key)) {
          key = i - s;
          l = key;
          break;
        }
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(s, s + mid))
          r = mid - 1;
        else
          l = mid + 1;
      }
      ans[cou2++] = sw(s, s + l);
      l = key, r = e - s;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(e - mid, e))
          r = mid - 1;
        else
          l = mid + 1;
      }
      ans[cou2++] = sw(e - l, e);
      break;
    } else
      mp[num[s]] -= 2;
  }
  if (cou2 == 0) {
    res = 1LL * (n + 1) * n / 2;
    cout << res << endl;
    return 0;
  }
  {
    int l1, l2, r1, r2;
    l1 = ans[0].l, l2 = ans[1].l;
    r1 = ans[0].r, r2 = ans[1].r;
    res += l1 * (n - r1 + 1) + (n - r2 + 1) * l2;
    res -= l1 * (n - r2 + 1);
    cout << res << endl;
  }
  return 0;
}
