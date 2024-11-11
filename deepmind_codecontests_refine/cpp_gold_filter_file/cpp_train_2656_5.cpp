#include <bits/stdc++.h>
using namespace std;
struct S {
  int dist, u, v;
  S(int dd, int uu, int vv) {
    dist = dd;
    u = uu;
    v = vv;
  }
  bool operator<(const S& a) const {
    if (dist != a.dist) return dist < a.dist;
    return u < a.u;
  }
  bool operator>(const S& a) const {
    if (dist != a.dist) return dist > a.dist;
    return u > a.u;
  }
};
vector<pair<int, int> > pA;
vector<pair<int, int> > pB;
vector<int> A;
vector<int> B;
pair<int, int> res[100007];
int main() {
  int N, M;
  scanf("%d %d ", &N, &M);
  ;
  for (int i = (0); i < (M); i++) {
    int a, b;
    scanf("%d %d ", &a, &b);
    ;
    if (b)
      A.push_back(a);
    else
      B.push_back(a);
    if (b)
      pA.push_back(make_pair(a, i));
    else
      pB.push_back(make_pair(a, i));
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(pA.begin(), pA.end());
  sort(pB.begin(), pB.end());
  priority_queue<S, vector<S>, greater<S> > pq;
  for (int i = (0); i < ((int)A.size() - 1); i++)
    pq.push(S(A[i + 1], i, i + 1));
  for (int m = (0); m < (B.size()); m++) {
    S s = pq.top();
    pq.pop();
    if (B[m] < s.dist) {
      cout << -1 << endl;
      return 0;
    }
    res[pB[m].second] = make_pair(s.u, s.v);
    s.v++;
    if (s.v < A.size()) {
      s.dist -= A[s.v - 1];
      s.dist += A[s.v];
      pq.push(s);
    }
  }
  for (int i = (0); i < (A.size()); i++)
    res[pA[i].second] = make_pair(i, N - 1);
  for (int i = (0); i < (M); i++)
    cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
  return 0;
}
