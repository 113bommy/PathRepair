#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef struct node2 {
  int d[60 + 1];
} node1;
node1 tree[400001];
int a[100001];
void initialise(int node, int b, int e) {
  if (b > e) {
    return;
  } else if (b == e) {
    for (int(i) = (0); (i) < (60); ++(i)) {
      tree[node].d[i] = 0;
    }
    return;
  } else {
    initialise(2 * node, b, (b + e) / 2);
    initialise(2 * node + 1, (b + e) / 2 + 1, e);
    for (int(i) = (0); (i) < (60); ++(i)) {
      tree[node].d[i] = 0;
    }
    return;
  }
}
void update(int node, int b, int e, int index, int val1) {
  if (b > e) {
    return;
  } else if (b == e && e == index) {
    for (int(i) = (0); (i) < (60); ++(i)) {
      tree[node].d[i] = 1;
      if (i % val1 == 0) {
        tree[node].d[i] += 1;
      }
    }
    return;
  } else {
    if (index <= (b + e) / 2) {
      update(2 * node, b, (b + e) / 2, index, val1);
    } else {
      update(2 * node + 1, (b + e) / 2 + 1, e, index, val1);
    }
    for (int(i) = (0); (i) < (60); ++(i)) {
      tree[node].d[i] = (tree[2 * node].d[i] +
                         tree[2 * node + 1].d[(tree[2 * node].d[i] + i) % 60]);
    }
    return;
  }
}
void query(node1 &res, int node, int b, int e, int i, int j) {
  if (b > e || b > j || e < i) {
    return;
  } else if (i <= b && e <= j) {
    res = tree[node];
    return;
  } else {
    node1 l, r;
    for (int(i) = (0); (i) < (60); ++(i)) {
      l.d[i] = 0;
      r.d[i] = 0;
    }
    query(l, 2 * node, b, (b + e) / 2, i, j);
    query(r, 2 * node + 1, (b + e) / 2 + 1, e, i, j);
    for (int(i) = (0); (i) < (60); ++(i)) {
      res.d[i] = (l.d[i] + r.d[(i + l.d[i]) % 60]);
    }
    return;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  initialise(1, 0, n - 1);
  for (int(i) = (0); (i) < (n); ++(i)) {
    int temp;
    scanf("%d", &temp);
    update(1, 0, n - 1, i, temp);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    char s[2];
    scanf("%s", s);
    if (s[0] == 'A') {
      int first, second;
      scanf("%d%d", &first, &second);
      first--;
      second--;
      second--;
      node1 res;
      for (int(i) = (0); (i) < (30); ++(i)) {
        res.d[i] = 0;
      }
      query(res, 1, 0, n - 1, first, second);
      printf("%d\n", res.d[0]);
    } else {
      int first, second;
      scanf("%d%d", &first, &second);
      first--;
      update(1, 0, n - 1, first, second);
    }
  }
  return 0;
}
