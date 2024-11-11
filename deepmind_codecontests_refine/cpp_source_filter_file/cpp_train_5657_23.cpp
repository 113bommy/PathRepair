#include <bits/stdc++.h>
using namespace std;
bool t1(pair<long long int, long long int> A,
        pair<long long int, long long int> B,
        pair<long long int, long long int> C) {
  return (A.first - B.first) * (C.second - B.second) >=
         (C.first - B.first) * (A.second - B.second);
}
bool t2(pair<long long int, long long int> A,
        pair<long long int, long long int> B,
        pair<long long int, long long int> C) {
  return (A.first - B.first) * (C.second - B.second) <=
         (C.first - B.first) * (A.second - B.second);
}
void ConvexHull(vector<pair<long long int, long long int> >& P) {
  P.erase(unique(P.begin(), P.end()), P.end());
  sort(P.begin(), P.end());
  vector<pair<long long int, long long int> > up, dn;
  for (int i = 0; i < P.size(); i++) {
    while (up.size() > 1 && t1(up[up.size() - 2], up[up.size() - 1], P[i]))
      up.pop_back();
    while (dn.size() > 1 && t2(dn[dn.size() - 2], dn[dn.size() - 1], P[i]))
      dn.pop_back();
    up.push_back(P[i]);
    dn.push_back(P[i]);
  }
  P = up;
  for (int i = dn.size() - 2; i >= 1; i--) P.push_back(dn[i]);
}
int main() {
  vector<pair<long long int, long long int> > P, Q;
  long long int n = []() {
    int first;
    scanf("%d", &first);
    return first;
  }();
  for (int i = 0; i < n; i++) {
    int first =
            []() {
              int first;
              scanf("%d", &first);
              return first;
            }(),
        second = []() {
          int first;
          scanf("%d", &first);
          return first;
        }();
    P.push_back({first, second});
    Q.push_back({first, second});
  }
  long long int m = []() {
    int first;
    scanf("%d", &first);
    return first;
  }();
  for (int i = 0; i < m; i++) {
    int first =
            []() {
              int first;
              scanf("%d", &first);
              return first;
            }(),
        second = []() {
          int first;
          scanf("%d", &first);
          return first;
        }();
    P.push_back({first, second});
  }
  ConvexHull(P), ConvexHull(Q);
  if (P == Q) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
