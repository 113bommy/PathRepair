#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 9;
const int Mod = 1000000007;
int A[N], n, B[N];
multiset<int> S;
bool ok(int l, int r) {
  if (l == r) {
    auto it = S.find(l);
    return it != S.end();
  }
  auto it = S.lower_bound(l);
  auto it2 = S.lower_bound(r);
  if (it == it2) {
    if (it2 != S.end() && (*it2) == r) return true;
    return false;
  } else {
    return true;
  }
}
const int Maxint = 29;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    S.insert(t);
  }
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = Maxint; j >= 0; j--) {
      if (A[i] & (1 << j)) {
        int Tp = tmp | 1 << j;
        if (ok(Tp, Tp + (1 << j) - 1)) {
          tmp = Tp;
        } else {
          ;
        }
      } else {
        if (ok(tmp, tmp + (1 << j) - 1)) {
          ;
        } else {
          tmp |= 1 << j;
        }
      }
    }
    B[i] = tmp;
    S.erase(S.lower_bound(tmp));
  }
  for (int i = 0; i < n; i++) printf("%d ", B[i] ^ A[i]);
}
