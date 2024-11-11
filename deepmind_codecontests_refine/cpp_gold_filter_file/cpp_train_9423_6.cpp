#include <bits/stdc++.h>
using namespace std;
const long N = 200010;
long long n;
long long before_Rep[2 * N];
long long after_Rep[2 * N];
void modify_1(long long p, long long value) {
  for (before_Rep[p += n] = value; p > 1; p >>= 1)
    before_Rep[p >> 1] = before_Rep[p] + before_Rep[p ^ 1];
}
void modify_2(long long p, long long value) {
  for (after_Rep[p += n] = value; p > 1; p >>= 1)
    after_Rep[p >> 1] = after_Rep[p] + after_Rep[p ^ 1];
}
long long query_1(long l, long r) {
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += before_Rep[l++];
    if (r & 1) res += before_Rep[--r];
  }
  return res;
}
long long query_2(long l, long r) {
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += after_Rep[l++];
    if (r & 1) res += after_Rep[--r];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  long long k, a, b, q, in1, in2;
  cin >> n >> k >> a >> b >> q;
  for (long i = 0; i < q; i++) {
    cin >> in1;
    if (in1 == 1) {
      cin >> in1 >> in2;
      modify_1(in1,
               max(min(in2 + before_Rep[in1 + n], b), before_Rep[in1 + n]));
      modify_2(in1, max(min(in2 + after_Rep[in1 + n], a), after_Rep[in1 + n]));
    } else {
      cin >> in1;
      cout << query_1(1, in1) + query_2(in1 + k, n + 1) << '\n';
    }
  }
  return 0;
}
