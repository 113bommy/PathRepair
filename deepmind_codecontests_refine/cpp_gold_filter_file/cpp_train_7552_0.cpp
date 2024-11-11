#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
int pom[2][2] = {{0, 1}, {1, 1}};
long long tmp;
void mulMat(int *A, int *B, int n) {
  int res[2][2] = {{0}};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        tmp = res[i][j];
        tmp += (*(A + i * n + k)) * 1LL * (*(B + k * n + j));
        if (tmp >= MOD)
          res[i][j] = tmp % MOD;
        else
          res[i][j] = tmp;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) *(A + i * n + j) = res[i][j];
}
void fastExp(int pot, int *T) {
  while (pot) {
    if (pot & 1) {
      mulMat(T, pom[0], 2);
    }
    mulMat(pom[0], pom[0], 2);
    pot >>= 1;
  }
  pom[0][0] = 0;
  pom[0][1] = 1;
  pom[1][0] = 1;
  pom[1][1] = 1;
}
struct Node {
  int mat[2][2];
  Node() {
    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 1;
  }
  Node(int pot) {
    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 1;
    fastExp(pot, mat[0]);
  }
};
void zbrojiMat(int *resMat, int *op1, int *op2) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      tmp = (*(op1 + i * 2 + j) + *(op2 + i * 2 + j));
      if (tmp >= MOD)
        *(resMat + i * 2 + j) = tmp - MOD;
      else
        *(resMat + i * 2 + j) = tmp;
    }
}
int n, m;
struct Node zeroe;
struct segTree {
  struct Node arr[1 << 18];
  struct Node lazy[1 << 18];
  int offset;
  struct Node neutralElem;
  void normalInit(int n) {
    for (offset = 1; offset < n; offset *= 2)
      ;
  }
  struct Node mergeValues(struct Node l, struct Node r) {
    struct Node n;
    zbrojiMat(n.mat[0], l.mat[0], r.mat[0]);
    return n;
  }
  segTree(int n) { normalInit(n); }
  void fillTree(int *data) {
    for (int i = offset; i < offset + n; i++)
      arr[i] = Node(*(data + i - offset));
    for (int i = offset - 1; i >= 1; i--)
      arr[i] = mergeValues(arr[i * 2], arr[i * 2 + 1]);
  }
  void updateRange(int lo, int hi, int *x) {
    update(1, 0, offset, lo, hi + 1, x);
  }
  struct Node query(int lo, int hi) {
    return q(1, 0, offset, lo, hi + 1);
  }

 private:
  void prop(int node) {
    mulMat(arr[node * 2].mat[0], lazy[node].mat[0], 2);
    mulMat(arr[node * 2 + 1].mat[0], lazy[node].mat[0], 2);
    mulMat(lazy[node * 2].mat[0], lazy[node].mat[0], 2);
    mulMat(lazy[node * 2 + 1].mat[0], lazy[node].mat[0], 2);
    lazy[node] = neutralElem;
  }
  void update(int node, int lo, int hi, int qlo, int qhi, int *T) {
    if (lo >= qhi or hi <= qlo) return;
    if (lo >= qlo && hi <= qhi) {
      mulMat(arr[node].mat[0], T, 2);
      mulMat(lazy[node].mat[0], T, 2);
      return;
    }
    prop(node);
    int mid = (lo + hi) / 2;
    if (node < offset) {
      update(node * 2, lo, mid, qlo, qhi, T);
      update(node * 2 + 1, mid, hi, qlo, qhi, T);
      arr[node] = mergeValues(arr[node * 2], arr[node * 2 + 1]);
    }
  }
  struct Node q(int node, int lo, int hi, int qlo, int qhi) {
    if (lo >= qhi || hi <= qlo) return zeroe;
    if (lo >= qlo && hi <= qhi) return arr[node];
    prop(node);
    int mid = (lo + hi) / 2;
    return mergeValues(q(node * 2, lo, mid, qlo, qhi),
                       q(node * 2 + 1, mid, hi, qlo, qhi));
  }
};
const int MAX = 100005;
int data[MAX];
segTree T(1);
int main() {
  int t;
  t = 1;
  while (t--) {
    zeroe.mat[0][0] = 0;
    zeroe.mat[1][1] = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      scanf("%d", &data[i]);
      data[i];
    }
    T.normalInit(n);
    T.fillTree(data);
    for (int i = 0; i < m; i++) {
      int id;
      scanf("%d", &id);
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      r--;
      if (id == 1) {
        int x;
        scanf("%d", &x);
        int Ti[2][2] = {{1, 0}, {0, 1}};
        fastExp(x, Ti[0]);
        T.updateRange(l, r, Ti[0]);
      } else {
        printf("%d\n", T.query(l, r).mat[0][1]);
      }
    }
  }
  return 0;
}
