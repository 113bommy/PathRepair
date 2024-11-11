#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
long long inv(long long x) { return expo(x, mod - 2); }
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int M = 2e5 + 5;
const long long Large = 1e11;
long long gap[M], segSum[M];
long long arr[M][2];
int main() {
  int n;
  long long h;
  cin >> n >> h;
  long long L, R;
  vector<pair<long long, int> > vec;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &(L));
    scanf("%lld", &(R));
    arr[i][0] = L;
    arr[i][1] = R;
    vec.push_back(make_pair(L, i));
  }
  sort(vec.begin(), vec.end());
  for (int i = 1; i < n; i++) {
    int indexx1 = vec[i - 1].second;
    int indexx2 = vec[i].second;
    gap[i] = arr[indexx2][0] - arr[indexx1][1] + gap[i - 1];
  }
  for (int i = 0; i < n; i++) {
    int indexx2 = vec[i].second;
    segSum[i] = (arr[indexx2][1] - arr[indexx2][0]);
    if (i != 0) {
      segSum[i] += segSum[i - 1];
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int indexx = vec[i].second;
    int lo = i, hi = n - 1;
    int ans = n - 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      long long drop = gap[mid] - gap[i];
      if (drop > h) {
        hi = mid - 1;
      } else {
        ans = mid;
        lo = mid + 1;
      }
    }
    long long dist = segSum[ans];
    if (i != 0) {
      dist -= segSum[i - 1];
    }
    long long drop = gap[ans] - gap[i];
    long long lefft = h - drop;
    dist += lefft;
    dist += drop;
    res = max(res, dist);
  }
  assert(res >= h);
  cout << res;
}
