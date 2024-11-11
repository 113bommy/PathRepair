#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
long long A[111111];
int I[111111];
long long P[111111];
long long PR[111111];
bool comp(int a, int b) { return A[a] < A[b]; }
int main() {
  int n;
  long long a, cf, cm, m;
  long long sum = 0;
  for (int i = 0; i < 111111; i++) {
    I[i] = i;
  }
  cin >> n >> a >> cf >> cm >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
  }
  if (n * a - sum <= m) {
    cout << n * cf + a * cm << '\n';
    for (int i = 0; i < n; i++) {
      cout << a << " ";
    }
    cout << '\n';
    return 0;
  }
  if (n == 1) {
    cout << (A[0] + m) * cm << '\n';
    cout << A[0] + m << '\n';
    return 0;
  }
  sort(I, I + n, comp);
  for (int ii = 0; ii < n; ii++) {
    int i = I[ii];
    if (ii) P[ii] = P[ii - 1];
    P[ii] += A[i];
  }
  for (int ii = n - 1; ii >= 0; ii--) {
    int i = I[ii];
    if (ii != n - 1) PR[ii] = PR[ii + 1];
    PR[ii] += A[i];
  }
  long long ans = -1;
  long long fst = -1, lsteq = -1;
  for (int ii = n; ii >= 0; ii--) {
    long long need1 = a * (n - ii) - PR[ii];
    if (need1 > m) break;
    long long rest = m - need1;
    if (A[I[1]] - A[I[0]] >= rest) {
      if (ans < (n - ii) * cf + (A[I[0]] + rest) * cm) {
        ans = (n - ii) * cf + (A[I[0]] + rest) * cm;
        fst = (n - ii);
        lsteq = A[I[0]] + rest;
      }
      continue;
    }
    long long ll = A[I[0]], rr = a;
    while (ll < rr) {
      long long mm = (ll + rr + 1) / 2;
      int ll2 = 0, rr2 = ii - 1;
      while (ll2 < rr2) {
        int m2 = (ll2 + rr2 + 1) / 2;
        if (A[I[m2]] > mm) {
          rr2 = m2 - 1;
        } else {
          ll2 = m2;
        }
      }
      if ((ll2 + 1) * mm - P[ll2] > rest) {
        rr = mm - 1;
      } else {
        ll = mm;
      }
    }
    long long na = (n - ii) * cf + ll * cm;
    if (ans < na) {
      ans = na;
      fst = (n - ii);
      lsteq = ll;
    }
  }
  for (int ii = 0; ii < fst; ii++) {
    m -= (a - A[I[n - ii - 1]]);
    A[I[n - ii - 1]] = a;
  }
  for (int ii = 0; ii < n; ii++) {
    if (A[I[ii]] >= lsteq) break;
    long long add = min(m, lsteq - A[I[ii]]);
    m -= add;
    A[I[ii]] += add;
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << '\n';
  return 0;
}
