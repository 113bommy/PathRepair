#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int max_n = (int)1e6 + 227 + 1;
const int max_int = (int)1e9 + 227 + 1;
const int mod = (int)1e9 + 7;
map<pair<long long, long long>, int> kek;
int main() {
  int t = next_int<int>();
  while (t--) {
    int type = next_int<int>();
    if (type == 1) {
      long long v = next_int<long long>();
      long long u = next_int<long long>();
      long long w = next_int<long long>();
      long long ve = v;
      long long ue = u;
      vector<long long> t[2];
      while (ve >= 1) {
        t[0].push_back(ve);
        ve /= 2;
      }
      while (ue >= 1) {
        t[1].push_back(ue);
        ue /= 2;
      }
      reverse(t[0].begin(), t[0].end());
      reverse(t[1].begin(), t[1].end());
      long long lca = -1;
      for (int i = t[0].size() - 1; i >= 0 && lca == -1; i--) {
        for (int j = t[1].size() - 1; j >= 0 && lca == -1; j--) {
          if (t[0][i] == t[1][j]) lca = t[0][i];
        }
      }
      while (v != lca) {
        kek[make_pair(v, v / 2)] += w;
        kek[make_pair(v / 2, v)] += w;
        v /= 2;
      }
      while (u != lca) {
        kek[make_pair(u, u / 2)] += w;
        kek[make_pair(u / 2, u)] += w;
        u /= 2;
      }
    } else {
      long long v = next_int<long long>();
      long long u = next_int<long long>();
      long long ve = v;
      long long ue = u;
      vector<long long> t[2];
      while (ve >= 1) {
        t[0].push_back(ve);
        ve /= 2;
      }
      while (ue >= 1) {
        t[1].push_back(ue);
        ue /= 2;
      }
      reverse(t[0].begin(), t[0].end());
      reverse(t[1].begin(), t[1].end());
      long long lca = -1;
      for (int i = t[0].size() - 1; i >= 0 && lca == -1; i--) {
        for (int j = t[1].size() - 1; j >= 0 && lca == -1; j--) {
          if (t[0][i] == t[1][j]) lca = t[0][i];
        }
      }
      long long ans = 0;
      while (v != lca) {
        ans += kek[make_pair(v, v / 2)];
        v /= 2;
      }
      while (u != lca) {
        ans += kek[make_pair(u, u / 2)];
        u /= 2;
      }
      cout << ans << "\n";
    }
  }
}
