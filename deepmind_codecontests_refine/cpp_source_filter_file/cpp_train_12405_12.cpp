#include <bits/stdc++.h>
using namespace std;
template <class T>
void re(T& x) {
  cin >> x;
}
template <class T1, class T2>
void re(pair<T1, T2>& x) {
  re(x.first);
  re(x.second);
}
template <class T>
void re(vector<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T>
void re(deque<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T1, class T2>
pair<T1, T2> mp(T1& x, T2& z) {
  return make_pair(x, z);
}
vector<long long> fact;
vector<vector<long> > edges;
long long mod = 998244353;
long long solve(long x, long p) {
  long long ret = 1;
  for (long i = 0; i < edges[x].size(); i++) {
    if (edges[x][i] != p) {
      ret *= solve(edges[x][i], x);
      ret %= mod;
    }
  }
  if (x == 1) {
    ret *= fact[edges[x].size()];
    ret %= mod;
  } else {
    ret *= fact[(edges[x].size() - 1)];
    ret %= mod;
    ret *= edges[x].size();
  }
  ret %= mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, z;
  cin >> n;
  edges.resize(n + 1);
  fact.resize(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  for (long i = 0; i < n - 1; i++) {
    cin >> x >> z;
    edges[x].push_back(z);
    edges[z].push_back(x);
  }
  cout << n * solve(1, 0) << endl;
  return 0;
}
