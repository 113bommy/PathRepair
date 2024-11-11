#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
const long long inf = 1e9;
int A[100000], B[100000], L[100000], R[100000];
int C[100000];
int n, m;
int find(int x) {
  if (x == C[x]) return x;
  return C[x] = find(C[x]);
}
bool ok(int po, int me) {
  for (int i = 1; i <= n; i++) C[i] = i;
  int a = L[po];
  int b = L[po] + me - 1;
  for (int i = 0; i < m; i++) {
    if (a >= L[i] && b <= R[i]) {
      int u = find(A[i]);
      int v = find(B[i]);
      if (u != v) {
        C[u] = v;
      }
    }
  }
  return find(1) == find(n);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> A[i] >> B[i] >> L[i] >> R[i];
  }
  int bes = 0;
  for (int i = 0; i < n; i++) {
    int ri = R[i] - L[i] + 1;
    int le = 0;
    int me;
    while (ri - le >= 5) {
      me = (ri + le) / 2;
      if (ok(i, me)) {
        le = me;
      } else
        ri = me;
    }
    for (me = ri; me >= le; me--)
      if (ok(i, me)) break;
    bes = max(bes, me);
  }
  if (bes == 0)
    cout << "Nice work, Dima!" << endl;
  else
    cout << bes << endl;
  return 0;
}
