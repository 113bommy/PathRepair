#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
struct BIT {
  int S;
  vector<T> v;
  BIT<T>(int _S) {
    S = _S;
    v.resize(S + 1);
  }
  void update(int i, T k) {
    for (i++; i <= S; i += i & -i) v[i] = v[i] + k;
  }
  T read(int i) {
    T sum = 0;
    for (i++; i; i -= i & -i) sum = sum + v[i];
    return sum;
  }
  T read(int l, int r) {
    if (l > r) return 0;
    return read(r) - read(l - 1);
  }
  int lower_bound(T sum) {
    T res = 0;
    int inx = 0;
    for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
      if ((inx + (1 << i) <= S) && res + v[inx + (1 << i)] < sum) {
        inx += 1 << i;
        res += v[inx];
      }
    }
    return inx;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int Q;
  cin >> Q;
  vector<char> op(Q);
  vi eel(Q);
  for (int q = 0; q < Q; q++) {
    cin >> op[q] >> eel[q];
  }
  vi vals = eel;
  sort((vals).begin(), (vals).end());
  vals.erase(unique((vals).begin(), (vals).end()), vals.end());
  BIT<int> ct(vals.size());
  BIT<ll> tot(vals.size());
  for (int q = 0; q < Q; q++) {
    int inx = lower_bound((vals).begin(), (vals).end(), eel[q]) - vals.begin();
    ct.update(inx, (op[q] == '+') ? 1 : -1);
    tot.update(inx, (op[q] == '+') ? eel[q] : -eel[q]);
    int qua = ct.read(vals.size() - 1);
    if (qua == 0) {
      cout << 0 << "\n";
      continue;
    }
    int ans = qua - 1;
    for (int i = ct.lower_bound(1); i < vals.size();) {
      ll sum = tot.read(i);
      int nxt =
          upper_bound((vals).begin(), (vals).end(), 2 * sum) - vals.begin();
      if (nxt == vals.size()) break;
      int btw = ct.read(i + 1, nxt - 1);
      int rem = ct.read(nxt, vals.size() - 1);
      if (rem == 0) break;
      if (btw == 0) {
        ans--;
        i = ct.lower_bound(ct.read(i) + 1);
      } else {
        i = nxt;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
