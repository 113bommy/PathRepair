#include <bits/stdc++.h>
using namespace std;
void task();
int main() {
  task();
  return 0;
}
const int N = (int)1e5 + 10;
const int MODULO = (int)1e9 + 3;
const long long int INF = (long long int)1e18;
const int BUF_SIZE = (int)1e5 + 10;
bool used[110];
int n, k;
int a[110], b[110];
long long int cat[110][110];
void comp_cat() {
  cat[0][0] = 0;
  for (int i = 1; i < 101; ++i) {
    cat[i][0] = cat[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      cat[i][j] = cat[i - 1][j - 1] + cat[i - 1][j];
    }
  }
}
void task() {
  scanf("%d %d", &n, &k);
  int cnt = n / k;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  double ansmin = 100500, ansmax = -1;
  int q;
  scanf("%d", &q);
  while (q--) {
    for (int i = 0; i < cnt; ++i) scanf("%d", &b[i]);
    int sum = 0;
    if (used[b[0]]) {
      continue;
    }
    for (int i = 0; i < cnt; ++i) {
      sum += a[b[i]];
      used[b[i]] = 1;
    }
    ansmin = min(ansmin, (double)sum / cnt);
    ansmax = max(ansmax, (double)sum / cnt);
  }
  vector<int> v;
  for (int i = 1; i <= n; ++i)
    if (!used[i]) v.push_back(a[i]);
  sort(v.begin(), v.end());
  int sz = v.size();
  (void(1));
  if (sz >= cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; ++i) {
      sum += v[i];
    }
    ansmin = min(ansmin, (double)sum / cnt);
    sum = 0;
    for (int i = sz - 1; i >= sz - cnt; --i) {
      sum += v[i];
    }
    ansmax = max(ansmax, (double)sum / cnt);
  }
  printf("%.10f %.10f", ansmin, ansmax);
}
