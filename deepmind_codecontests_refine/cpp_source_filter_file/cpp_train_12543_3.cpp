#include <bits/stdc++.h>
using namespace std;
struct node {
  int u;
  int v;
} edge[1000010];
int nn;
void deal(int p, int k) {
  for (int i = 1; i < k; i++) {
    edge[nn].u = p;
    edge[nn++].v = p + i;
  }
  int temp;
  temp = (k - 3) / 2;
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < temp; j++) {
      edge[nn].u = p + i;
      edge[nn++].v = p + (i + j) % (k - 1);
    }
  }
  for (int i = 1; i < k; i++) {
    edge[nn].u = p + k;
    edge[nn++].v = p + i;
    edge[nn].u = p + k + 1;
    edge[nn++].v = p = i;
  }
  edge[nn].u = p + k;
  edge[nn++].v = p + k + 1;
}
int main() {
  int k, x;
  cin >> k;
  if (k % 2 == 0) {
    cout << "NO" << endl;
  } else if (k == 1) {
    cout << "YES" << endl;
    cout << "2 1" << endl;
    cout << "1 2" << endl;
  } else {
    cout << "YES" << endl;
    x = 2 * (k + 2);
    deal(1, k);
    deal(x / 2 + 1, k);
    edge[nn].u = 1;
    edge[nn++].v = x / 2 + 1;
    cout << x << " " << nn << endl;
    for (int i = 0; i < nn; i++) {
      printf("%d %d\n", edge[i].u, edge[i].v);
    }
  }
  return 0;
}
