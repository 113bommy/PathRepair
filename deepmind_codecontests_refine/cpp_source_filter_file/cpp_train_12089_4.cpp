#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 10, LOG = 19;
int pos[N], rnk[LOG][N], P[N], L[N], R[N], lcp[N], n, q;
char second[N];
void BuildSuffixArray() {
  for (int i = 1; i <= n; i++) rnk[0][i] = second[i], P[i] = i;
  for (int pw = 1; pw < LOG; pw++) {
    auto cmp = [&](int x, int y) {
      if (rnk[pw - 1][x] != rnk[pw - 1][y])
        return rnk[pw - 1][x] < rnk[pw - 1][y];
      if (max(x, y) + (1 << (pw - 1)) > n) return x > y;
      return rnk[pw - 1][x + (1 << (pw - 1))] <
             rnk[pw - 1][y + (1 << (pw - 1))];
    };
    sort(P + 1, P + n + 1, cmp);
    rnk[pw][P[1]] = 1;
    for (int i = 2; i <= n; i++)
      rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
  }
}
int LCP(int x, int y) {
  if (x == y) return n - x + 1;
  if (x > y) swap(x, y);
  int tes = 0;
  for (int i = LOG - 1; i >= 0; i--)
    if (y + (1 << i) <= n + 1 && rnk[i][x] == rnk[i][y]) {
      tes |= (1 << i);
      x += (1 << i), y += (1 << i);
    }
  return tes;
}
long long int get(vector<int> &A, vector<int> B = {}) {
  vector<int> C;
  merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
  for (int &x : C) x = pos[x];
  sort(C.begin(), C.end());
  for (int i = 0; i + 1 < (long long int)C.size(); i++) {
    lcp[i] = LCP(P[C[i]], P[C[i + 1]]);
  }
  for (int i = 0; i + 1 < (long long int)C.size(); i++) {
    for (L[i] = i - 1; L[i] >= 0 && lcp[L[i]] >= lcp[i]; L[i] = L[L[i]])
      ;
  }
  for (int i = (long long int)C.size() - 2; i >= 0; i--) {
    for (R[i] = i + 1; R[i] + 1 < (long long int)C.size() && lcp[R[i]] > lcp[i];
         R[i] = R[R[i]])
      ;
  }
  long long int res = 0;
  for (int i = 0; i + 1 < (long long int)C.size(); i++)
    res += 1LL * (i - L[i]) * (R[i] - i) * lcp[i];
  return res;
}
int main() {
  scanf("%d%d%s", &n, &q, second + 1);
  BuildSuffixArray();
  for (int i = 1; i <= n; i++) pos[P[i]] = i;
  while (q--) {
    int k, l;
    scanf("%d%d", &k, &l);
    vector<int> A, B;
    for (int i = 1; i <= k; i++) {
      int x;
      scanf("%d", &x);
      A.push_back(x);
    }
    for (int i = 1; i <= l; i++) {
      int x;
      scanf("%d", &x);
      B.push_back(x);
    }
    printf("%lld\n", get(A, B) - get(A) - get(B));
  }
  return 0;
}
