#include <bits/stdc++.h>
using namespace std;
void ASS(bool bb) {
  if (!bb) {
    ++*(int*)0;
  }
}
#pragma comment(linker, "/STACK:106777216")
vector<long long> u;
const int N = 1 << 17;
struct RSQ {
  int a[N * 2];
  void Add(int pos) {
    for (int i = pos + N; i; i >>= 1) a[i]++;
  }
  int Sum(int L, int R) {
    int res = 0;
    for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
      if (L & 1) res += a[L++];
      if (R & 1) res += a[--R];
    }
    return res;
  }
  void Clear() { memset(a, 0, sizeof(a)); }
};
RSQ rsq;
int FindGr(long long val) {
  int L = -1;
  int R = (int)u.size();
  while (R - L > 1) {
    int m = (L + R) >> 1;
    if (val < u[m])
      R = m;
    else
      L = m;
  }
  return R;
}
long long Cnt(long long val, const vector<long long>& sums,
              const vector<int>& vind) {
  rsq.Clear();
  rsq.Add(vind[0]);
  long long res = 0;
  for (int i = 1; i < (int)sums.size(); i++) {
    res += rsq.Sum(0, FindGr(sums[i] - val));
    rsq.Add(vind[i]);
  }
  return res;
}
int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  vector<long long> sums(n + 1, 0);
  for (int i = 0; i < (int)(n); i++) sums[i + 1] = sums[i] + a[i];
  u = sums;
  sort(u.begin(), u.end());
  u.resize(unique(u.begin(), u.end()) - u.begin());
  map<long long, int> ind;
  for (int i = 0; i < (int)(u.size()); i++) ind[u[i]] = i;
  vector<int> vind(n + 1);
  for (int i = 0; i < (int)(sums.size()); i++) vind[i] = ind[sums[i]];
  const long long inf = (long long)(1e16 + 2e9);
  long long L = -inf;
  long long R = inf;
  while (R - L > 1) {
    long long m = (L + R) / 2;
    if (Cnt(m, sums, vind) >= k)
      L = m;
    else
      R = m;
  }
  cout << L << endl;
  return 0;
}
