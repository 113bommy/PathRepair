#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int N = (int)(3e5 + 20);
const int L = 360;
const long long int M = (int)(1e9 + 7);
const double E = 1e-7;
bool isPal = true;
bool canBePalindrome = false;
int a[N], cnt[N];
int cnts[N], cntL[N], cntR[N];
struct solution {
  long long int left, right, total;
  solution(long long int l, long long int r, long long int t)
      : left(l), right(r), total(t) {}
};
long long int solveR(long long int l, long long int r) {
  int dif = 0;
  int bl = l, br = r;
  bool canPal = true;
  int cntOdd = 0;
  for (int i = l; i <= r; ++i) {
    cnts[a[i]]++;
    cntOdd += (cnts[a[i]] & 1) ? 1 : -1;
  }
  int lastChanged = br;
  while (bl < br) {
    int o = r - (bl - l);
    if (o < bl) break;
    if (cnts[a[bl]] < 2 - (o == l)) {
      lastChanged = bl;
      break;
    }
    if (a[o] != a[bl]) {
      lastChanged = o;
    }
    cnts[a[bl]] -= 2;
    bl++;
  }
  return lastChanged - l + 1;
}
long long int solveL(long long int l, long long int r) {
  int dif = 0;
  int bl = l, br = r;
  bool canPal = true;
  int cntOdd = 0;
  for (int i = l; i <= r; ++i) {
    cnts[a[i]]++;
    cntOdd += (cnts[a[i]] & 1) ? 1 : -1;
  }
  int lastChanged = br;
  while (bl < br) {
    int o = l + (r - br);
    if (o > br) break;
    if (cnts[a[br]] < 2 - (o == l)) {
      lastChanged = br;
      break;
    }
    if (a[o] != a[br]) {
      lastChanged = o;
    }
    cnts[a[bl]] -= 2;
    br--;
  }
  return r - lastChanged + 1;
}
solution solve(long long int l, long long int r) {
  if (l == r) return solution(1, 1, 1);
  if (a[l] == a[r]) {
    solution sol = solve(l + 1, r - 1);
    sol.left *= 2;
    sol.right *= 2;
    sol.total = sol.left + sol.right - 1;
    return sol;
  }
  long long int rans = solveR(l, r);
  reverse(a + l, a + r + 1);
  memset(cnts, 0, N * sizeof(int));
  long long int lans = solveR(l, r);
  return solution(lans, rans, lans + rans - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int n;
  cin >> n;
  int cntOdd = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
    isPal &= (i < (n / 2)) || a[i] == a[n - i - 1];
    cntOdd += (cnt[a[i]] & 1) ? 1 : -1;
  }
  canBePalindrome = cntOdd <= 1;
  if (isPal)
    cout << (n * (n + 1) / 2);
  else if (!canBePalindrome)
    cout << 0;
  else
    cout << solve(0, n - 1).total;
}
