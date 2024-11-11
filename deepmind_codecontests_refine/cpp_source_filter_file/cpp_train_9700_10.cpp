#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int a[128];
int N, K;
int used[128];
double mx = -1, mn = 1e+9;
void scan() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> a[i];
  int Q;
  cin >> Q;
  for (int j = 0; j < Q; ++j) {
    int sz = N / K;
    double sum = 0;
    for (int i = 0; i < sz; ++i) {
      int tmp;
      cin >> tmp;
      sum += ((double)a[tmp - 1] / (double)sz);
      used[tmp - 1] = 1;
    }
    mn = min(mn, sum);
    mx = max(mx, sum);
  }
}
void solve() {
  for (int i = 0; i < N; ++i)
    if (!used[i]) v.push_back(a[i]);
  sort(v.begin(), v.end());
  if (v.size() > N - N % K && v.size() >= N / K) {
    double sum = 0;
    double sz = N / K;
    for (int i = 0; i < N / K; ++i) sum += ((double)v[i] / sz);
    mn = min(mn, sum);
    reverse(v.begin(), v.end());
    sum = 0;
    for (int i = 0; i < N / K; ++i) sum += ((double)v[i] / sz);
    mx = max(mx, sum);
  }
  printf("%.7f %.7f\n", mn, mx);
}
int main() {
  scan();
  solve();
}
