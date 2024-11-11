#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  long long L, R, S;
};
int N, M, D[300010], H[300010];
long long DS[300010], inf = 1LL << 62;
Node tree[2400000];
long long getD(int s, int e) { return DS[e] - DS[s]; }
void build(int i, int s, int e) {
  if (s == e) {
    tree[i].L = 2 * H[s % N];
    tree[i].R = 2 * H[s % N];
    tree[i].S = 2 * H[s % N];
  } else {
    int md = (s + e) / 2;
    build(2 * i + 1, s, md);
    build(2 * i + 2, md + 1, e);
    tree[i].L = max(tree[2 * i + 1].L, getD(s, md + 1) + tree[2 * i + 2].L);
    tree[i].R = max(tree[2 * i + 2].R, tree[2 * i + 1].R + getD(md, e));
    tree[i].S = max(tree[2 * i + 1].R + tree[2 * i + 2].L + getD(md, md + 1),
                    max(tree[i * 2 + 1].S, tree[i * 2 + 2].S));
  }
}
long long query(int i, int Ss, int Se, int Qs, int Qe, int op) {
  if (Qe < Ss || Se < Qs) return -inf;
  if (op == 0) {
    if (Qs <= Ss && Se <= Qe)
      return tree[i].S;
    else {
      int md = (Ss + Se) / 2;
      long long q1 = query(2 * i + 1, Ss, md, Qs, Qe, 1) + getD(md, md + 1) +
                     query(2 * i + 2, md + 1, Se, Qs, Qe, 2);
      long long q2 = query(2 * i + 1, Ss, md, Qs, Qe, 0);
      long long q3 = query(2 * i + 2, md + 1, Se, Qs, Qe, 0);
      return max(q1, max(q2, q3));
    }
  } else if (op == 1) {
    if (Qs <= Ss && Se <= Qe)
      return tree[i].R;
    else {
      int md = (Ss + Se) / 2;
      long long q1 = query(2 * i + 2, md + 1, Se, Qs, Qe, 1);
      long long q2 = query(2 * i + 1, Ss, md, Qs, Qe, 1) + getD(md, Se);
      return max(q1, q2);
    }
  } else {
    if (Qs <= Ss && Se <= Qe)
      return tree[i].L;
    else {
      int md = (Ss + Se) / 2;
      long long q1 = query(2 * i + 1, Ss, md, Qs, Qe, 2);
      long long q2 = getD(Ss, md + 1) + query(2 * i + 2, md + 1, Se, Qs, Qe, 2);
      return max(q1, q2);
    }
  }
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> D[i];
  for (int i = 1; i < 2 * N; i++) DS[i] = D[(i - 1) % N] + DS[i - 1];
  for (int i = 0; i < N; i++) cin >> H[i];
  build(0, 0, 2 * N - 1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a <= b) {
      cout << query(0, 0, 2 * N - 1, b + 1, a - 1 + N, 0) << endl;
    } else {
      cout << query(0, 0, 2 * N - 1, b + 1, a - 1, 0) << endl;
    }
  }
  return 0;
}
