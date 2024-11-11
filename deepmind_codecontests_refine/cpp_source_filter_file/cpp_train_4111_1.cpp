#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;
const long long MOD = 1000000007;
const long long mod = 998244353;
const long double eps = 1e-12;
long long n;
long long arr[300001];
long long res;
long long Lmax[300001], Lmin[300001];
long long Rmax[300001], Rmin[300001];
long long cnt[600001];
const long long D = 300000;
void solve(long long L, long long R) {
  if (L == R) {
    res++;
    return;
  }
  long long mid = (L + R) / 2;
  solve(L, mid);
  solve(mid + 1, R);
  Lmax[mid] = arr[mid];
  Lmin[mid] = arr[mid];
  for (long long i = mid - 1; i >= L; i--) {
    Lmax[i] = max(arr[i], Lmax[i + 1]);
    Lmin[i] = min(arr[i], Lmin[i + 1]);
  }
  Rmax[mid + 1] = arr[mid + 1];
  Rmin[mid + 1] = arr[mid + 1];
  for (long long i = (mid + 2); i <= (R); i += (1)) {
    Rmax[i] = max(arr[i], Rmax[i - 1]);
    Rmin[i] = min(arr[i], Rmin[i - 1]);
  }
  for (long long i = (L); i <= (mid); i += (1)) {
    long long dif = Lmax[i] - Lmin[i];
    long long j = i + dif;
    if (mid + 1 <= j and j <= R and Lmin[i] < Rmin[j] and Rmax[j] < Lmax[i]) {
      res++;
    }
  }
  for (long long i = R; i >= mid + 1; i--) {
    long long dif = Rmax[i] - Rmin[i];
    long long j = i - dif;
    if (L <= j and j <= mid and Rmin[i] < Lmin[j] and Lmax[j] < Rmax[i]) {
      res++;
    }
  }
  long long Lptr = R + 1;
  long long Rptr = R;
  vector<long long> vis;
  for (long long i = (L); i <= (mid); i += (1)) {
    while (Lptr > mid + 1 and Rmax[Lptr - 1] > Lmax[i]) {
      Lptr--;
      if (Lptr <= Rptr) {
        cnt[Rmax[Lptr] - Lptr + D]++;
        vis.push_back(Rmax[Lptr] - Lptr + D);
      }
    }
    while (Rptr >= mid + 1 and Rmin[Rptr] <= Lmin[i]) {
      if (Lptr <= Rptr) {
        cnt[Rmax[Rptr] - Rptr + D]--;
        vis.push_back(Rmax[Rptr] - Rptr + D);
      }
      Rptr--;
    }
    long long T = Lmin[i] - i;
    res += cnt[T + D];
  }
  for (long long i : vis) {
    cnt[i] = 0;
  }
  vis.clear();
  Lptr = L;
  Rptr = L - 1;
  for (long long i = R; i >= mid + 1; i--) {
    while (Lptr <= mid and Lmin[Lptr] <= Rmin[i]) {
      if (Lptr <= Rptr) {
        cnt[Lmax[Lptr] + Lptr + D]--;
        vis.push_back(Lmax[Lptr] + Lptr + D);
      }
      Lptr++;
    }
    while (Rptr < mid and Lmax[Rptr + 1] > Rmax[i]) {
      Rptr++;
      if (Lptr <= Rptr) {
        cnt[Lmax[Rptr] + Rptr + D]++;
        vis.push_back(Lmax[Rptr] + Rptr + D);
      }
    }
    long long T = Rmin[i] + i;
    res += cnt[T + D];
  }
  for (long long i : vis) {
    cnt[i] = 0;
  }
  vis.clear();
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = (0); i <= (n - 1); i += (1)) {
    long long idx, val;
    cin >> idx >> val;
    idx--;
    arr[idx] = val;
  }
  solve(0, n - 1);
  cout << res << '\n';
  return 0;
}
