#include <bits/stdc++.h>
using namespace std;
void RD(int &x) { scanf("%d", &x); }
void RD(long long &x) { scanf("%I64d", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(long long &x, long long &y) { scanf("%I64d%I64d", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(char *s) { scanf("%s", s); }
void RD(char &s) { scanf("%c", &s); }
void RD(string &s) { cin >> s; }
void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(long long x) { printf("%I64d\n", x); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }
const long long inf = 1LL << 28;
const long long mod = 1LL;
int arr[1010];
long long cyclen;
long long a, b, w, x, c, cnt;
bool ok(long long mid) {
  long long i, k, aa, cc;
  cc = c;
  cc -= mid;
  k = (mid / cyclen) * cnt;
  for (i = 0; i < (mid % cyclen); i++) k += arr[i + 1];
  aa = a;
  aa -= k;
  return (cc <= aa);
}
map<int, int> mp;
int main() {
  int i, j, k;
  long long bb, lo, hi, mid, ans;
  while (scanf("%I64d", &a) == 1) {
    RD(b, w);
    RD(x, c);
    bb = b;
    (mp.clear());
    cnt = 0;
    cyclen = 0;
    memset(arr, 0, sizeof(arr));
    for ((i) = 1; (i) <= (int)(10000); (i)++) {
      if (bb >= x) {
        bb -= x;
        if (mp.find(bb) != mp.end()) break;
      } else {
        bb = w - (x - bb);
        if (mp.find(bb) != mp.end()) break;
        arr[i] = 1;
        cnt++;
      }
      mp[bb] = 1;
      cyclen++;
    }
    lo = 0;
    ans = hi = 4 * 1e14;
    while (lo <= hi) {
      mid = (lo + hi) >> 1LL;
      if (ok(mid))
        ans = mid, hi = mid - 1;
      else
        lo = mid + 1;
    }
    PR(ans);
  }
  return 0;
}
