#include <bits/stdc++.h>
using namespace std;
long long hot = 0;
struct util {
  long long l, r, idx;
  long long ans;
};
util brr[200005];
long long b_size;
long long arr[200005];
long long mp[200005];
bool comp(util a, util b) {
  long long x = a.l / b_size;
  long long y = b.l / b_size;
  if (x == y)
    return a.r < b.r;
  else
    return x < y;
}
void add(long long val) {
  hot -= (mp[val] * mp[val] * val);
  mp[val]++;
  hot += (mp[val] * mp[val] * val);
}
void rem(long long val) {
  hot -= (mp[val] * mp[val] * val);
  mp[val]--;
  hot += (mp[val] * mp[val] * val);
}
bool comp2(util a, util b) {
  if (a.idx < b.idx)
    return true;
  else
    return false;
}
int main() {
  long long n, q;
  scanf("%lld", &n);
  ;
  b_size = (long long)sqrt(n);
  scanf("%lld", &q);
  ;
  for (long long i = 0; i < n; i++) scanf("%lld", &arr[i]);
  ;
  for (long long i = 0; i < q; i++) {
    brr[i].idx = i;
    long long x, y;
    scanf("%lld", &x);
    ;
    scanf("%lld", &y);
    ;
    x--;
    y--;
    brr[i].l = x;
    brr[i].r = y;
  }
  sort(brr, brr + q, comp);
  long long l1 = 0, r1 = -1;
  for (long long i = 0; i < q; i++) {
    while (r1 < brr[i].r) {
      r1++;
      add(arr[r1]);
    }
    while (r1 > brr[i].r) {
      rem(arr[r1]);
      r1--;
    }
    while (l1 < brr[i].l) {
      rem(arr[l1]);
      l1++;
    }
    while (l1 > brr[i].l) {
      l1--;
      add(arr[l1]);
    }
    brr[i].ans = hot;
  }
  sort(brr, brr + q, comp2);
  for (long long i = 0; i < q; i++) cout << brr[i].ans << "\n";
}
