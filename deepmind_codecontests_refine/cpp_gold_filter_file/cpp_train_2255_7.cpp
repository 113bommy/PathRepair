#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5;
long long N, Q;
long long A[MAXN];
long long prefSum[MAXN];
long long binsearch(long long l, long long r, long long val) {
  long long mid = (l + r) / 2;
  if (l == r - 1) {
    if (prefSum[r] <= val) {
      return r;
    }
    return l;
  }
  if (prefSum[mid] <= val) {
    return binsearch(mid, r, val);
  } else {
    return binsearch(l, mid, val);
  }
}
int main() {
  cin >> N >> Q;
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
  }
  prefSum[0] = 0;
  for (long long i = 1; i <= N; i++) {
    prefSum[i] = prefSum[i - 1] + A[i - 1];
  }
  for (long long i = N + 1; i < MAXN; i++) {
    prefSum[i] = 1LL << 60;
  }
  long long cur = 0;
  for (long long i = 0; i < Q; i++) {
    long long k;
    cin >> k;
    cur += k;
    long long res = binsearch(0, 2 * N, cur);
    if (res >= N) {
      cur = 0;
    }
    if (res < N) {
      cout << N - res << endl;
    } else {
      cout << N << endl;
    }
  }
}
