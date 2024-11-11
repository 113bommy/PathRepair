#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
long long n, m;
vector<pair<long long, long long> > v;
long long mod = 1000000007LL;
long long stree[4 * 200050];
map<long long, int> M;
set<long long> S;
void update(int node, int left, int right, int pos, long long val) {
  if (pos < left || right < pos) return;
  if (left == right) {
    stree[node] = val;
    return;
  }
  int mid = (left + right) / 2;
  update(node * 2, left, mid, pos, val);
  update(node * 2 + 1, mid + 1, right, pos, val);
  stree[node] = stree[node * 2] % mod + stree[node * 2 + 1] % mod;
  return;
}
long long query(int node, int left, int right, int srch_l, int srch_r) {
  if (srch_l <= left && right <= srch_r) return stree[node];
  if (right < srch_l || left > srch_r) return 0;
  int mid = (left + right) / 2;
  long long ret1 = query(node * 2, left, mid, srch_l, srch_r);
  ret1 %= mod;
  long long ret2 = query(node * 2 + 1, mid + 1, right, srch_l, srch_r);
  ret2 %= mod;
  long long ret = (ret1 + ret2) % mod;
  return ret;
}
vector<int> adj[200050];
int main(void) {
  long long a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b, v.push_back(make_pair(a, b));
    S.insert(a);
    S.insert(b);
  }
  S.insert(0);
  S.insert(n);
  int track = 0;
  for (__typeof((S).begin()) it = (S.begin()); it != (S).end(); ++it)
    M[*it] = track++;
  n = (int)M.size() - 1;
  update(1, 0, n, 0, 1);
  for (int i = 0; i < (int)v.size(); i++) {
    long long right = v[i].second;
    right = M[right];
    adj[right].push_back(i);
  }
  for (int i = 1; i < (int)M.size(); i++) {
    long long val = 0;
    for (int j = 0; j < (int)adj[i].size(); j++) {
      int indx = adj[i][j];
      int left = v[indx].first;
      int right = v[indx].second;
      left = M[left];
      right = M[right];
      val += query(1, 0, n, left, right);
      val %= mod;
    }
    update(1, 0, n, i, val);
  }
  deb(query(1, 0, n, n, n));
  return 0;
}
