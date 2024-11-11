#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);
const double eps = (double)1e-9;
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 300500;
const int shift = 300001;
long long ans;
pair<int, int> p[N];
bool u[N];
int cnt[N + N];
int n, x[N], y[N];
int mnl[N], mxl[N];
int mnr[N], mxr[N];
void calc(int l, int r) {
  if (l == r) {
    ans++;
    return;
  }
  int mid = (l + r) >> 1;
  calc(l, mid);
  calc(mid + 1, r);
  mnl[mid + 1] = N;
  mxl[mid + 1] = 0;
  mnr[mid] = N;
  mxr[mid] = 0;
  long long dif = 0;
  for (int i = mid; i >= l; i--) {
    mnl[i] = min(mnl[i + 1], y[i]);
    mxl[i] = max(mxl[i + 1], y[i]);
  }
  for (int i = mid + 1; i <= r; i++) {
    mnr[i] = min(mnr[i - 1], y[i]);
    mxr[i] = max(mxr[i - 1], y[i]);
  }
  for (int i = l; i <= mid; i++) {
    int pos = i + mxl[i] - mnl[i];
    if (mid < pos && pos <= r && mnl[i] < mnr[pos] && mxr[pos] < mxl[i]) dif++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int pos = i - mxr[i] + mnr[i];
    if (l <= pos && pos <= mid && mnr[i] < mnl[pos] && mxl[pos] < mxr[i]) dif++;
  }
  int ptrmn = mid;
  int ptrmx = mid + 1;
  for (int i = mid + 1; i <= r; i++) {
    while (ptrmn >= l && mnl[ptrmn] > mnr[i]) {
      if (ptrmx <= ptrmn) cnt[mnl[ptrmn] - ptrmn + shift]--;
      ptrmn--;
    }
    while (ptrmx > l && mxl[ptrmx - 1] < mxr[i]) {
      ptrmx--;
      if (ptrmx <= ptrmn) cnt[mnl[ptrmx] - ptrmx + shift]++;
    }
    dif += cnt[mxr[i] - i + shift];
  }
  for (int i = l; i <= mid; i++) cnt[mnl[i] - i + shift] = 0;
  ptrmn = mid + 1;
  ptrmx = mid;
  for (int i = mid + 1; i <= r; i++) {
    while (ptrmn > l && mnl[ptrmn - 1] > mnr[i]) {
      ptrmn--;
      if (ptrmn <= ptrmx) cnt[mxl[ptrmn] + ptrmn]++;
    }
    while (ptrmx >= l && mnl[ptrmx] < mxr[i]) {
      if (ptrmn <= ptrmx) cnt[mxl[ptrmx] + ptrmx]--;
      ptrmx--;
    }
    dif += cnt[mnr[i] + i];
  }
  for (int i = l; i <= mid; i++) cnt[mxl[i] + i] = 0;
  ans += dif;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i], p[i] = {x[i], y[i]};
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) x[i] = p[i].first, y[i] = p[i].second;
  calc(1, n);
  cout << ans;
  return 0;
}
