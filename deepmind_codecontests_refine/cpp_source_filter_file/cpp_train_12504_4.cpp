#include <bits/stdc++.h>
using namespace std;
void scann(long long &x) {
  x = 0;
  long long ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
}
void printn(long long x) {
  if (x == 0) putchar('0');
  char buf[32];
  long long i = 0;
  while (x) {
    long long y = x / 10, z = x - 10 * y;
    buf[i++] = z + '0';
    x = y;
  }
  while (i) {
    putchar(buf[--i]);
  }
  putchar('\n');
}
long long cnt[222222], pref[222222];
int main() {
  long long n, k, a, MAX = 0, MIN = 222222;
  cin >> n >> k;
  vector<long long> v;
  for (long long i = 0; i < 222222; i++) {
    cnt[i] = 0;
    pref[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    scann(a);
    MAX = max(a, MAX);
    cnt[a - 1]++;
  }
  for (long long i = MAX - 2; i >= 0; i--) cnt[i] += cnt[i + 1];
  if (cnt[MAX - 1] == n) {
    cout << 0;
    return 0;
  }
  long long s = 0;
  while (cnt[s] == n) s++;
  pref[0] = cnt[0];
  for (long long i = 1; i < MAX; i++) pref[i] += cnt[i] + pref[i - 1];
  for (long long i = 0; i < MAX; i++) {
    pref[i] -= s * n;
    pref[i] = max(pref[i], 0ll);
    v.push_back(pref[i]);
  }
  long long S = 1;
  for (vector<long long>::iterator jt = v.begin() + MAX - 1; jt != v.begin();)
    if ((*jt) > k) {
      S++;
      vector<long long>::iterator it;
      it = upper_bound(v.begin(), jt, (*jt) - k);
      jt = it;
    } else {
      cout << S;
      return 0;
    }
}
