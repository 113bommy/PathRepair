#include <bits/stdc++.h>
using namespace std;
bool p[10000001];
long h[10000001];
struct S {
  long a, c;
} s[1000000];
int n;
int k;
long a[1000001];
int binl(int x) {
  if (x == 2) return 0;
  if (x > s[k - 1].a) return -1;
  int mid = (0 + k - 1) / 2;
  int l = 0, r = k - 1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (s[mid].a >= x && s[mid - 1].a < x && mid - 1 >= 0)
      return mid;
    else if (s[mid].a < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
int binr(int x) {
  if (x > s[k - 1].a) return k - 1;
  int mid = (0 + k - 1) / 2;
  int l = 0, r = k - 1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (s[mid].a <= x && s[mid + 1].a > x && mid + 1 < k)
      return mid;
    else if (s[mid].a < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  for (int i = 2; i <= 10000000; i++) {
    if (p[i] == 0) {
      s[k].a = i;
      s[k].c = 0;
      for (int j = i; j <= 10000000; j += i) {
        p[j] = 1;
        s[k].c += h[j];
      }
      k++;
    }
  }
  for (int i = 1; i < k; i++) s[i].c += s[i - 1].c;
  int m;
  long long l, r, ans;
  cin >> m;
  while (m--) {
    cin >> l >> r;
    int ll = binl(l);
    int rr = binr(r);
    if (ll == -1 || rr == -1) {
      cout << 0 << endl;
      continue;
    }
    cout << s[rr].c - ((ll > 0) ? s[ll - 1].c : 0) << endl;
  }
  return 0;
}
