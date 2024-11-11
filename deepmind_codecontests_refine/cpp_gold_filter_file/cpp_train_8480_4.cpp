#include <bits/stdc++.h>
using namespace std;
const signed long long Infinity = 1000000100;
const long double Epsilon = 1e-9;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& V) {
  os << "[";
  for (int(i) = (0); (i) < (int(V.size())); (i)++)
    os << V[i] << ((i == int(V.size()) - 1) ? "" : ",");
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& S) {
  os << "(";
  for (__typeof(S.begin()) i = S.begin(); i != S.end(); ++i)
    os << *i << (*i == *S.rbegin() ? "" : ",");
  return os << ")";
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& M) {
  os << "{";
  for (__typeof(M.begin()) i = M.begin(); i != M.end(); ++i)
    os << *i << (*i.first == M.rbegin()->first ? "" : ",");
  return os << "}";
}
int first[30300][2020];
int V[30300];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int(i) = (1); (i) <= (n); (i)++) {
    int p;
    scanf("%d", &p);
    V[p]++;
  }
  int ans = V[d];
  n = 30001;
  int magic = 600;
  for (int(i) = (d); (i) <= (n); (i)++)
    for (int(j) = (0); (j) <= (magic); (j)++) first[i][j] = -1;
  first[d][magic / 2] = V[d];
  for (int(i) = (d); (i) <= (n); (i)++) {
    for (int(j) = (0); (j) <= (magic); (j)++) {
      ans = max(ans, first[i][j]);
      int v = first[i][j];
      int l = d + j - magic / 2;
      if (v == -1) continue;
      if (l + i <= n) {
        first[l + i][j] = max(v + V[l + i], first[l + i][j]);
      }
      if (l + i + 1 <= n) {
        first[l + i + 1][j + 1] =
            max(v + V[l + i + 1], first[l + i + 1][j + 1]);
        ;
      }
      if (l + i - 1 <= n and l > 1) {
        first[l + i - 1][j - 1] =
            max(v + V[l + i - 1], first[l + i - 1][j - 1]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
