#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& o, const pair<int64_t, int64_t>& p) {
  return o << "(" << p.first << " " << p.second << ") ";
}
struct seg {
  pair<int64_t, int64_t> p, q;
};
int main() {
  int T;
  cin >> T;
  while (T--) {
    seg G[3];
    pair<int64_t, int64_t> A, B, C, D, E;
    bool gotB = 0, gotD = 0;
    map<pair<int64_t, int64_t>, int> st;
    for (int i = 0; i < 3; ++i) {
      cin >> G[i].p.first >> G[i].p.second >> G[i].q.first >> G[i].q.second;
      st[G[i].p]++;
      st[G[i].q]++;
    }
    if (st.size() != 5) {
      puts("NO");
      continue;
    }
    for (auto P : st) {
      if (P.second == 2) {
        A = P.first;
      }
    }
    for (int i = 0; i < 3; ++i) {
      if (G[i].p == A) {
        if (gotB)
          C = G[i].q;
        else {
          gotB = true;
          B = G[i].q;
        }
      } else if (G[i].q == A) {
        if (gotB)
          C = G[i].p;
        else {
          gotB = true;
          B = G[i].p;
        }
      } else {
        E = G[i].p;
        D = G[i].q;
      }
    }
    B.first -= A.first;
    B.second -= A.second;
    C.first -= A.first;
    C.second -= A.second;
    D.first -= A.first;
    D.second -= A.second;
    E.first -= A.first;
    E.second -= A.second;
    if (B.first * C.first + B.second * C.second < 0 ||
        B.first * C.second - B.second * C.first == 0) {
      puts("NO");
      continue;
    }
    if (B.first * D.second - B.second * D.first != 0) swap(D, E);
    int64_t u1 = B.first * D.first + B.second * D.second,
            u2 = C.first * E.first + C.second * E.second;
    int64_t v1 = B.first * B.first + B.second * B.second,
            v2 = C.first * C.first + C.second * C.second;
    if (u1 * 5 < v1 || u1 * 5 > v1 * 4 ||
        B.first * D.second - B.second * D.first != 0) {
      puts("NO");
      continue;
    }
    if (u2 * 5 < v1 || u2 * 5 > v2 * 4 ||
        C.first * E.second - C.second * E.first != 0) {
      puts("NO");
      continue;
    }
    puts("YES");
  }
}
