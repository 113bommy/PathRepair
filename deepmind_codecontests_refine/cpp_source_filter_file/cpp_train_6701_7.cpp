#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 23;
const int MOD = 1e9 + 7;
const int N = 100 + 10;
bool pcomp(int* a, int* b, int n) {
  for (int i = (1); i < (n + 1); ++i)
    if (a[i] != b[i]) {
      return false;
    }
  return true;
}
void papply(int* a, int* q, int n) {
  int tmp[N];
  for (int i = (1); i < (n + 1); ++i) tmp[i] = a[i];
  for (int i = (1); i < (n + 1); ++i) tmp[i] = a[q[i]];
  for (int i = (1); i < (n + 1); ++i) a[i] = tmp[i];
}
int go(int* st, int* en, int* q, int n, int k) {
  if (pcomp(st, en, n)) {
    return 0;
  }
  int tmp[N];
  for (int i = (1); i < (n + 1); ++i) tmp[i] = st[i];
  for (int i = (1); i < (k + 1); ++i) {
    papply(tmp, q, n);
    if (pcomp(tmp, en, n)) {
      return i;
    }
  }
  return -1;
}
int q[N];
int s[N];
int p[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = (1); i < (n + 1); ++i) cin >> q[i];
  for (int i = (1); i < (n + 1); ++i) cin >> s[i];
  for (int i = (1); i < (n + 1); ++i) p[i] = i;
  int steps1 = go(p, s, q, n, k);
  int steps2 = go(s, p, q, n, k);
  bool ans = false;
  if (steps1 == 1 && steps2 == 1)
    ans = k == 1;
  else {
    ans |= steps1 > 1 && (k - steps1) % 2 == 0;
    ans |= steps2 > 1 && (k - steps2) % 2 == 0;
  }
  cout << (ans ? "YES" : "NO") << "\n";
}
