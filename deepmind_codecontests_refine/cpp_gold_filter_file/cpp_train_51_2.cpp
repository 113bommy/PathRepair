#include <bits/stdc++.h>
int n, k, q;
unsigned int a, b;
unsigned int query(unsigned int BIT[], int day) {
  unsigned int result = 0;
  for (int i = day; i > 0; i -= (i & -i)) {
    result += BIT[i];
  }
  return result;
}
unsigned int query(unsigned int BIT[], int left, int right) {
  unsigned int l = query(BIT, left - 1);
  unsigned int r = query(BIT, right);
  return query(BIT, right) - query(BIT, left - 1);
}
void update(unsigned int BIT[], unsigned int rate, int day, int orders) {
  int value = rate - query(BIT, day, day);
  if (value > 0) {
    orders = std::min(orders, value);
    for (int i = day; i < n + 1; i += (i & -i)) {
      BIT[i] += orders;
    }
  }
}
int main() {
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  unsigned int BIT_A[n + 1];
  unsigned int BIT_B[n + 1];
  memset(&BIT_A, (0), sizeof(BIT_A));
  memset(&BIT_B, (0), sizeof(BIT_B));
  for (int _ = 0; (_) < int(q); (_)++) {
    int op;
    scanf(" %d", &op);
    int day, orders;
    if (op == 1) {
      scanf(" %d", &day);
      scanf(" %d", &orders);
      update(BIT_A, a, day, orders);
      update(BIT_B, b, day, orders);
      if (false) printf("BIT A\n");
      for (int i = 1; i < n + 1; i++)
        if (false) printf("%d\n", BIT_A[i]);
      if (false) printf("BIT B\n");
      for (int i = 1; i < n + 1; i++)
        if (false) printf("%d\n", BIT_B[i]);
    } else if (op == 2) {
      scanf(" %d", &day);
      unsigned int q_a = query(BIT_A, day + k, n);
      unsigned int q_b = query(BIT_B, 1, day - 1);
      if (false) printf("query on BIT A: %d\nquery on BIT B: %d\n", q_a, q_b);
      unsigned int result = q_a + q_b;
      printf("%d\n", result);
    }
  }
}
