#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
const int DIM = 200005;
struct stru {
  pair<int, int> val;
  int pos;
};
stru aux[DIM];
string str;
int cod[LOG][DIM];
pair<int, int> qry[DIM * 2];
inline bool cmp(stru st1, stru st2) { return st1.val < st2.val; }
int _n;
inline int lcp(int p1, int p2) {
  int ans = 0;
  for (int k = LOG - 1; k >= 0; --k) {
    if (cod[k][p1] == cod[k][p2] and max(p1, p2) + (1 << k) - 1 <= _n) {
      ans += (1 << k), p1 += (1 << k), p2 += (1 << k);
    }
  }
  return ans;
}
inline bool cmp2(const pair<int, int> &p1, const pair<int, int> &p2) {
  if (p1.first == p2.first) {
    return p1.second < p2.second;
  }
  int l = lcp(p1.first, p2.first),
      cd1 = (p1.first + l > _n ? -1 : str[p1.first + l - 1]),
      cd2 = (p2.first + l > _n ? -1 : str[p2.first + l - 1]);
  return cd1 < cd2;
}
inline void debug(void) {
  cout << lcp(1, 2);
  exit(0);
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q >> str;
  _n = n;
  for (int i = 1; i <= n; ++i) {
    cod[0][i] = str[i - 1] - 'a';
  }
  for (int k = 1; k < LOG; ++k) {
    for (int i = 1; i <= n; ++i) {
      aux[i].val = make_pair(cod[k - 1][i], i + (1 << (k - 1)) <= n
                                                ? cod[k - 1][i + (1 << (k - 1))]
                                                : -1);
      aux[i].pos = i;
    }
    sort(aux + 1, aux + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
      cod[k][aux[i].pos] =
          (i > 1) and aux[i].val == aux[i - 1].val ? cod[k][aux[i - 1].pos] : i;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    for (int i = 1; i <= l; ++i) {
      cin >> qry[i].first;
      qry[i].second = 1;
    }
    for (int i = l + 1; i <= l + r; ++i) {
      cin >> qry[i].first;
      qry[i].second = 2;
    }
    sort(qry + 1, qry + l + r + 1, cmp2);
    long long ans = 0;
    for (int s = 1; s <= 2; ++s) {
      long long sum = 0;
      map<int, int> cnt;
      for (int i = 1; i <= l + r; ++i) {
        int pos = qry[i].first, typ = qry[i].second;
        if (typ == 2) {
          ans += sum;
        } else {
          ++cnt[n - pos + 1];
          sum += n - pos + 1;
        }
        if (i + 1 <= l + r) {
          int len = lcp(qry[i].first, qry[i + 1].first);
          while (!cnt.empty()) {
            auto it = prev(cnt.end());
            if (it->first <= len) {
              break;
            }
            sum -= 1LL * it->first * it->second;
            cnt[len] += it->second;
            sum += 1LL * it->second * len;
            cnt.erase(it);
          }
        }
      }
      reverse(qry + 1, qry + l + r + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
