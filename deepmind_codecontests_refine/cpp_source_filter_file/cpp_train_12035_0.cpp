#include <bits/stdc++.h>
using namespace std;
long long dc(long long len, long long k) {
  long long mid = (len + 1) / 2;
  if (k == 1) return mid;
  k--;
  long long leftlen = mid - 1, rightlen = len - mid;
  map<pair<pair<long long, long long>, long long>, long long> segments;
  if (leftlen)
    segments[make_pair(make_pair((leftlen - 1) / 2, 0), leftlen & 1)]++;
  if (rightlen)
    segments[make_pair(make_pair((rightlen - 1) / 2, 1), rightlen & 1)]++;
  long long gotleft = 0, gotright = 0;
  while (1) {
    int type = segments.begin()->first.first.second;
    long long l = segments.begin()->first.first.first;
    l *= 2;
    if (segments.begin()->first.second)
      l++;
    else
      l += 2;
    long long cnt = segments.begin()->second;
    segments.erase(segments.begin());
    long long sh = (l - 1) / 2;
    if (l == 2) {
      if (type == 0) {
        gotleft += cnt * 2;
      } else {
        gotright += cnt * 2;
      }
    } else {
      if (l > 1) {
        segments[make_pair(make_pair((sh - 1) / 2, type), sh & 1)] += cnt;
        sh = l - sh - 1;
        segments[make_pair(make_pair((sh - 1) / 2, type), sh & 1)] += cnt;
      }
      if (type == 0) {
        gotleft += cnt;
      } else {
        gotright += cnt;
      }
    }
    if (gotleft + gotright >= k) {
      if (type)
        return mid + dc(rightlen, k - gotleft);
      else
        return dc(leftlen, k - gotright);
    }
  }
}
long long solve(long long n, long long k) {
  if (k == 1) return 1;
  if (k == 2) return n;
  n -= 2;
  k -= 2;
  return 1 + dc(n, k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  cout << solve(n, k) << '\n';
  return 0;
}
