#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 2e5 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
const int SQ = 320;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int Cnt[SQ][N];
vector<int> Time, Num;
pair<int, int> D[N];
inline int mpT(int x) {
  return (int)(lower_bound((Time).begin(), (Time).end(), x) - Time.begin());
}
inline int mpN(int x) {
  return (int)(lower_bound((Num).begin(), (Num).end(), x) - Num.begin());
}
inline void U(int X, int t, int x, int del) {
  Cnt[X][x] += del;
  D[t] = make_pair(x, del);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<pair<int, pair<int, int> > > Q;
  Time.push_back(0);
  Num.push_back(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int w, t, x;
    cin >> w >> t >> x;
    Q.push_back(make_pair(w, make_pair(t, x)));
    Time.push_back(t);
    Num.push_back(x);
  }
  sort((Time).begin(), (Time).end());
  sort((Num).begin(), (Num).end());
  for (int i = 0; i < q; i++) {
    int w = Q[i].first, t = mpT(Q[i].second.first), x = mpN(Q[i].second.second);
    if (w == 1) {
      U(t / SQ, t, x, +1);
    } else if (w == 2) {
      U(t / SQ, t, x, -1);
    } else {
      int ind = 0, sum = 0;
      for (int T = 0; T <= SQ; T++) {
        if (((T + 1) * SQ - 1) > t) {
          ind = T * SQ + 1;
          break;
        } else {
          sum += Cnt[T][x];
        }
      }
      for (int j = ind; j <= t; j++) {
        if (D[j].first == x) {
          sum += D[j].second;
        }
      }
      cout << sum << "\n";
    }
  }
  return 0;
}
