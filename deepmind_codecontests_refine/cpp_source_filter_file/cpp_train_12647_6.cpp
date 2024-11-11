#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
vector<int> prime[500001];
int isp[500001];
long long cnt[500001], mob[500001], ar[500001], on[500001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i <= 500000; i++) {
    if (isp[i] == 0) {
      for (int j = i; j <= 500000; j += i) {
        isp[j] = 1;
        prime[j].push_back(i);
      }
    }
  }
  int n, q;
  cin >> n >> q;
  for (int i = (1); i < (n + 1); ++i) cin >> ar[i];
  long long res = 0, t = 0;
  for (int i = (0); i < (q); ++i) {
    int v;
    cin >> v;
    if (on[v]) {
      for (int j = (0); j < (1 << prime[ar[v]].size()); ++j) {
        long long p = 1, c = 0;
        for (int k = (0); k < (prime[ar[v]].size()); ++k) {
          if (j & 1 << k) {
            p *= prime[ar[v]][k];
            c++;
          }
        }
        if (p == 1) continue;
        if (c % 2 == 1) {
          cnt[p]--;
          res -= cnt[p];
        } else {
          cnt[p]--;
          res += cnt[p];
        }
      }
      on[v] = 0;
      t--;
    } else {
      on[v] = 1;
      t++;
      for (int j = (0); j < (1 << prime[ar[v]].size()); ++j) {
        long long p = 1, c = 0;
        for (int k = (0); k < (prime[ar[v]].size()); ++k) {
          if (j & 1 << k) {
            p *= prime[ar[v]][k];
            c++;
          }
        }
        if (p == 1) continue;
        if (c % 2 == 1) {
          res += cnt[p];
          cnt[p]++;
        } else {
          res += cnt[p];
          cnt[p]++;
        }
      }
    }
    long long out = t * (t - 1);
    out /= 2ll;
    out -= res;
    cout << out << endl;
  }
}
