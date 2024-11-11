#include <bits/stdc++.h>
using namespace std;
long long pow2[100] = {0}, r;
vector<long long> other;
bool tryh(long long h) {
  vector<long long> cpy(other);
  long long pown[100];
  copy(pow2, pow2 + 100, pown);
  for (long long i = 0; i < (100); ++i) {
    for (long long j = 0; j < (pown[i] - h); ++j) {
      cpy.push_back(1 << i);
    }
    pown[i] = min(pown[i], h);
  }
  sort(cpy.begin(), cpy.end());
  for (int i = r - 1; i >= 0 && !cpy.empty(); --i) {
    for (int j = 0; j < pown[i] - pown[i + 1] && !cpy.empty(); ++j) {
      if (cpy.back() < (1 << (i + 1)))
        cpy.pop_back();
      else
        return false;
    }
  }
  if (((int)(cpy).size())) return false;
  return true;
}
int main() {
  long long(n);
  scanf("%lld", &n);
  long long a;
  for (long long i = 0; i < (n); ++i) {
    scanf("%lld", &(a));
    if (__builtin_popcountll(a) == 1)
      ++pow2[__builtin_ffsll(a) - 1];
    else
      other.push_back(a);
  }
  for (long long i = (1); i < (100); ++i) {
    if (pow2[i] > pow2[i - 1]) {
      for (long long j = 0; j < (pow2[i] - pow2[i - 1]); ++j) {
        other.push_back(1 << i);
      }
      pow2[i] = pow2[i - 1];
    }
  }
  r = find(pow2, pow2 + 100, 0) - pow2;
  sort(other.begin(), other.end());
  if (!tryh(pow2[0])) return 0 * puts("-1");
  long long L = 0, R = pow2[0], mid;
  while (R - L > 1) {
    mid = (L + R) / 2;
    (tryh(mid) ? R : L) = mid;
  }
  for (long long i = R; i <= pow2[0]; ++i) {
    printf("%lld%c", i, " \n"[i == pow2[0]]);
  }
}
