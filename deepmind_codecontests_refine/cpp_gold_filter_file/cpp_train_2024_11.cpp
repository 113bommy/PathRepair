#include <bits/stdc++.h>
using namespace std;
int a[333000], b[333000], x[333000], y[333000], ty[333000];
long long B2[333000], B1[333000], xl[333000];
double bl[333000];
void U(int ind, int v, long long *B) {
  for (ind += 5; ind < 333000; ind += (ind & -ind)) B[ind] += v;
}
long long Q(int ind, long long *B) {
  long long ret = 0;
  for (ind += 5; ind; ind -= (ind & -ind)) ret += B[ind];
  return ret;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  int nm = n;
  for (int i = 0; i < q; i++) {
    scanf("%d", &ty[i]);
    if (ty[i] == 1) {
      scanf("%d%d", &x[i], &y[i]);
      b[nm++] = y[i];
    } else {
      cin >> xl[i];
    }
  }
  sort(b, b + nm);
  nm = unique(b, b + nm) - b;
  map<int, int> M;
  for (int i = 0; i < nm; i++) M[b[i]] = i;
  for (int i = 0; i < n; i++) {
    U(M[a[i]], 1, B1);
    U(M[a[i]], a[i], B2);
  }
  for (int i = 0; i < nm; i++) bl[i] = b[i];
  for (int i = 0; i < q; i++) {
    if (ty[i] == 1) {
      int j = x[i] - 1;
      U(M[a[j]], -1, B1);
      U(M[a[j]], -a[j], B2);
      a[j] = y[i];
      U(M[a[j]], 1, B1);
      U(M[a[j]], a[j], B2);
    } else {
      double hi = 1e16, lo = 0, mid;
      for (int j = 0; j < 80; j++) {
        mid = (hi + lo) * 0.5;
        long long lob = ceil(mid);
        int ind = lower_bound(bl, bl + nm, double(lob)) - bl;
        int quan = Q(ind - 1, B1);
        long long filled = Q(ind - 1, B2);
        double have = quan * mid - filled;
        if (have >= xl[i]) {
          hi = mid;
        } else
          lo = mid;
      }
      printf("%.10lf\n", hi);
    }
  }
}
