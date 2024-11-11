#include <bits/stdc++.h>
const int MaxN = 200111;
const int AINT_SIZE = MaxN * 5;
struct AINT_NODE {
  long long sum, aux;
};
int N, size, op, x, val;
AINT_NODE aint[AINT_SIZE];
int q_st, q_dr, q_val;
inline void Augment(int nod, int st, int dr) {
  int l = nod << 1;
  int r = l + 1;
  aint[nod].sum += aint[nod].aux * (dr - st + 1);
  if (st < dr) {
    aint[l].aux += aint[nod].aux;
    aint[r].aux += aint[nod].aux;
  }
  aint[nod].aux = 0;
}
void Update(int nod, int st, int dr) {
  if (q_st <= st && dr <= q_dr) {
    if (q_val == -1337) {
      aint[nod].sum = 0;
    } else {
      aint[nod].aux += q_val;
      Augment(nod, st, dr);
    }
    return;
  }
  int mid = st + ((dr - st) >> 1);
  int l = nod << 1;
  int r = l + 1;
  Augment(l, st, mid);
  Augment(r, mid + 1, dr);
  if (q_st <= mid) {
    Update(l, st, mid);
  }
  if (mid < q_dr) {
    Update(r, mid + 1, dr);
  }
  aint[nod].sum = aint[l].sum + aint[r].sum;
}
int main() {
  scanf("%d", &N);
  size = 1;
  for (register int i = 1; i <= N; ++i) {
    scanf("%d", &op);
    if (op == 2) {
      scanf("%d", &x);
      ++size;
      q_st = size;
      q_dr = size;
      q_val = x;
      Augment(1, 1, MaxN);
      Update(1, 1, MaxN);
    } else if (op == 1) {
      scanf("%d %d", &x, &val);
      q_st = 1;
      q_dr = x;
      q_val = val;
      Augment(1, 1, MaxN);
      Update(1, 1, MaxN);
    } else {
      q_st = size;
      q_dr = size;
      q_val = -1337;
      Augment(1, 1, MaxN);
      Update(1, 1, MaxN);
      --size;
    }
    printf("%.6lf\n", (double)(aint[1].sum) / (double)(size));
  }
  return 0;
}
