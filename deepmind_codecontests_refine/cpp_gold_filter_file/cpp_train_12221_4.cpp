#include <bits/stdc++.h>
using std::cin;
using std::cout;
int n, m, k, cnt[10000000 + 2], a[1000000 + 1], mx, pr[10000000 + 1];
long long ans;
std::vector<int> pv;
std::vector<long long> need;
int max(int a, int b) { return (a < b) ? b : a; }
void in() {
  cin >> k;
  mx = 0;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
    mx = max(mx, a[i]);
  }
  for (int i = mx; i >= 1; --i) cnt[i] += cnt[i + 1];
}
void sprime() {
  for (int i = 2; i <= mx; ++i) pr[i] = -1;
  for (int i = 2; i <= mx; ++i)
    if (pr[i] == -1) {
      int id = pv.size();
      pr[i] = id;
      for (int j = i + i; j <= mx; j += i) pr[j] = id;
      pv.push_back(i);
    }
}
void sfact() {
  need.resize(pv.size());
  for (int i = 1; i <= mx; ++i) {
    for (int j = i; j > 1; j /= pv[pr[j]]) need[pr[j]] += cnt[i];
  }
}
bool check(long long x) {
  for (int i = 0; i < pv.size(); ++i) {
    long long sum = 0;
    int p = pv[i];
    for (long long j = p; j <= x; j *= p) sum += x / j;
    if (sum < need[i]) return 0;
  }
  return 1;
}
long long bsearch() {
  long long mn = 0;
  for (int i = 0; i < k; ++i) mn += a[i];
  long long f = mx, l = mn;
  while (f <= l) {
    long long mid = (f + l) >> 1;
    if (check(mid)) {
      mn = mid;
      l = mid - 1;
    } else
      f = mid + 1;
  }
  return mn;
}
void prs() {
  sprime();
  sfact();
  ans = bsearch();
}
void out() { cout << ans; }
void run() {
  in();
  prs();
  out();
}
int main() {
  run();
  return 0;
}
