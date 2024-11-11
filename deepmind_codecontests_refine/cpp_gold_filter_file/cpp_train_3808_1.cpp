#include <bits/stdc++.h>
using namespace std;
long long int pref[51];
long long int sf[51];
long long int sum[51];
long long int maxi[51];
long long int a[255001];
int main() {
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);
    long long int s = 0;
    for (int j = 0; j < l; j++) {
      scanf("%lld", &a[j]);
      s = s + a[j];
    }
    sum[i] = s;
    long long int pr = s;
    s = 0;
    for (int j = 0; j < l; j++) {
      s = s + a[j];
      pr = max(pr, s);
    }
    pref[i] = pr;
    long long int suf = s;
    s = 0;
    for (int j = l - 1; j >= 0; j--) {
      s = s + a[j];
      suf = max(suf, s);
    }
    sf[i] = suf;
    maxi[i] = a[0];
    long long int val = a[0];
    for (int j = 1; j < l; j++) {
      val = max(val + a[j], a[j]);
      maxi[i] = max(maxi[i], val);
    }
  }
  long long int s = 0;
  for (int i = 0; i < m; i++) {
    scanf("%lld", &a[i]);
    s = s + sum[a[i] - 1];
  }
  long long int fmaxi = s;
  long long int pmov = 0;
  for (int i = 0; i < m; i++) {
    int idx = a[i] - 1;
    fmaxi = max(maxi[idx], fmaxi);
    fmaxi = max(fmaxi, pref[idx] + pmov);
    pmov = max(pmov + sum[idx], sf[idx]);
    pmov = max(pmov, (long long int)0);
  }
  cout << fmaxi << endl;
}
