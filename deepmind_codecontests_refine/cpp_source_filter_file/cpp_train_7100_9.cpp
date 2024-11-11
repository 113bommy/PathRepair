#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "{";
  for (const T& v : vc) o << v << ",";
  o << "}";
  return o;
}
using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int _ = 0; _ < (int)(T); _++) {
    int N;
    cin >> N;
    V<int> v(N);
    V<int> when(N);
    V<int> col(N);
    for (int i = 0; i < (int)(N); i++) {
      int x;
      cin >> x;
      x--;
      v[i] = x;
      when[x] = i;
    }
    function<void(V<int>, int)> solve = [&](V<int> v, int offc) {
      sort(v.begin(), v.end());
      V<int> tv = v;
      sort(tv.begin(), tv.end(),
           [&](int x, int y) { return when[x] < when[y]; });
      true;
      true;
      auto setc = [&](int x, int c) { col[x] = c + offc; };
      auto Doit = [&](V<int> nei, int me) {
        nei.push_back(me);
        sort(nei.begin(), nei.end());
        V<bool> okc(3, true);
        int K = nei.size();
        if (K <= 3) {
          for (int i = 0; i < (int)(K); i++)
            if (nei[i] != me) {
              okc[col[nei[i]] - offc] = false;
            }
        } else {
          for (int i = 0; i < (int)(K); i++)
            if (nei[i] == me) {
              if (i != 0) okc[col[nei[i - 1]] - offc] = false;
              if (i != K - 1) okc[col[nei[i + 1]] - offc] = false;
            }
        }
        for (int c = 0; c < (int)(3); c++)
          if (okc[c]) {
            setc(me, c);
            break;
          }
      };
      if ((int)tv.size() <= 4) {
        V<int> before;
        for (int x : tv) {
          Doit(before, x);
          before.push_back(x);
        }
        return;
      }
      int K = v.size();
      V<int> nv((K + 2) / 3, -1);
      map<int, int> ID;
      set<int> marked;
      for (int i = 0; i < (int)(N); i++) ID[v[i]] = i;
      for (int x : tv) {
        int id = ID[x];
        if (nv[id / 3] == -1) {
          nv[id / 3] = x;
          marked.insert(x);
        }
      }
      solve(nv, offc + 3);
      set<int> st;
      st.insert(-1);
      st.insert(N);
      for (int x : tv) {
        if (marked.count(x)) {
          st.insert(x);
          continue;
        }
        true;
        true;
        V<int> nei;
        {
          auto it = st.lower_bound(x);
          it--;
          while (true) {
            int a = *it;
            if (a == -1 || marked.count(a)) break;
            nei.push_back(a);
            it--;
          }
          it = st.lower_bound(x);
          while (true) {
            int a = *it;
            if (a == N || marked.count(a)) break;
            nei.push_back(a);
            it++;
          }
        }
        sort(nei.begin(), nei.end());
        Doit(nei, x);
        st.insert(x);
      }
    };
    solve(v, 1);
    for (int i = 0; i < (int)(N); i++) cout << col[i] << " ";
    cout << endl;
  }
}
