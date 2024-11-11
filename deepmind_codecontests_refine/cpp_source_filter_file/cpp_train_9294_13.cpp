#include <bits/stdc++.h>
using namespace std;
template <typename elemType>
inline void Read(elemType &T) {
  elemType X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  T = (w ? -X : X);
}
const int maxn = 100010;
struct SegmentTree {
  int T[maxn << 2];
  void Update(int Root, int L, int R, int pos, int val) {
    if (L == R) {
      T[Root] = val;
      return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
      Update(Root << 1, L, mid, pos, val);
    else
      Update(Root << 1 | 1, mid + 1, R, pos, val);
    T[Root] = min(T[Root << 1], T[Root << 1 | 1]);
  }
  int Query(int Root, int L, int R, int QL, int QR) {
    if (QR < L || R < QL) return 1 << 30;
    if (QL <= L && R <= QR) return T[Root];
    int mid = (L + R) >> 1;
    return min(Query(Root << 1, L, mid, QL, QR),
               Query(Root << 1 | 1, mid + 1, R, QL, QR));
  }
};
SegmentTree Tree;
int data[maxn];
bool mex[maxn];
int N;
int main() {
  Read(N);
  bool flag = true;
  for (int i = 1; i <= N; ++i) {
    Read(data[i]);
    if (data[i] != 1) flag = false;
  }
  if (flag) {
    printf("1\n");
    return 0;
  }
  mex[1] = true;
  for (int i = 1; i <= N; ++i) {
    if (data[i] == 1) {
      Tree.Update(1, 1, N, data[i], i);
      continue;
    }
    if (Tree.Query(1, 1, N + 1, 1, data[i] - 1) >
        Tree.Query(1, 1, N + 1, data[i], data[i]))
      mex[data[i]] = true;
    Tree.Update(1, 1, N + 1, data[i], i);
  }
  for (int i = 2; i <= N + 1; ++i)
    if (Tree.Query(1, 1, N + 1, 1, i - 1) > Tree.Query(1, 1, N + 1, i, i))
      mex[i] = true;
  for (int i = 1; i <= N + 2; ++i)
    if (!mex[i]) {
      printf("%d\n", i);
      break;
    }
  return 0;
}
