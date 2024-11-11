#include <bits/stdc++.h>
using namespace std;
long long left_ptr, right_ptr, res, result[100001][101], m[100001], cd, need,
    cnt[100001], cut[100001][101], d[100001];
void inp() {
  cin >> cd >> need;
  for (long long i = 1; i <= cd; i++) cin >> m[i];
  for (long long i = 0; i <= cd; i++)
    for (long long e = 0; e <= need; e++) result[i][e] = 1e15;
  result[0][0] = 0;
}
long long cost(long long L, long long R) {
  while (left_ptr > L) res += cnt[m[--left_ptr]]++;
  while (right_ptr < R) res += cnt[m[++right_ptr]]++;
  while (left_ptr < L) res -= --cnt[m[left_ptr++]];
  while (right_ptr > R) res -= --cnt[m[right_ptr--]];
  return res;
}
void calc(long long g, long long l, long long r, long long optl,
          long long optr) {
  if (l > r) return;
  long long mid = (l + r) / 2;
  long long got = 0, h, st = mid;
  if (mid > optr) st = optr;
  for (long long i = st; i >= optl; i--) {
    long long got = cost(i, mid);
    if (got + result[i - 1][g - 1] < result[mid][g]) {
      cut[mid][g] = i;
      result[mid][g] = got + result[i - 1][g - 1];
    }
  }
  calc(g, mid + 1, r, cut[mid][g], optr);
  calc(g, l, mid - 1, optl, cut[mid][g]);
}
void do_it() {
  left_ptr = 1;
  right_ptr = cd;
  long long got = 0, h;
  for (long long i = 1; i <= cd; i++) {
    cnt[m[i]]++;
    h = cnt[m[i]] - 1;
    got -= h * (h - 1) / 2;
    h++;
    got += h * (h - 1) / 2;
    result[i][1] = got;
    res = got;
  }
  for (long long i = 2; i <= need; i++) calc(i, 1, cd, 1, cd);
  cout << result[cd][need];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  inp();
  do_it();
}
