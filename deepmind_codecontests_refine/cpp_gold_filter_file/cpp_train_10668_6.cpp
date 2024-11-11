#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long S;
  cin >> n >> k >> S;
  int a[30];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long fac[50];
  fac[0] = 1;
  for (int i = 1; i < 50; i++) {
    fac[i] = i * fac[i - 1];
    if (fac[i] > 10000000000000000ll) fac[i] = 10000000000000001ll;
  }
  int bit = n / 2;
  bit++;
  map<pair<long long, int>, long long> mp;
  int lim = pow(3ll, (long long)bit);
  for (int i = 0; i < lim; i++) {
    int rem = i;
    int cnt = 0;
    long long sm = 0;
    for (int j = 0; j < bit; j++) {
      if (rem % 3 == 2) {
        cnt++;
        sm += fac[min(49, a[j])];
      } else if (rem % 3 == 1)
        sm += a[j];
      rem /= 3;
    }
    pair<long long, int> p = make_pair(sm, cnt);
    mp[p]++;
  }
  long long r = 0;
  int bit2 = n - bit;
  lim = pow(3ll, (long long)bit2);
  for (int i = 0; i < lim; i++) {
    int rem = i;
    int cnt = 0;
    long long sm = 0;
    for (int j = 0; j < bit2; j++) {
      if (rem % 3 == 2) {
        cnt++;
        sm += fac[min(49, a[j + bit])];
      } else if (rem % 3 == 1)
        sm += a[j + bit];
      rem /= 3;
    }
    for (int K = cnt; K <= k; K++) {
      pair<long long, int> p = make_pair(S - sm, k - K);
      r += mp[p];
    }
  }
  cout << r << endl;
}
