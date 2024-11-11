#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int cnt;
  node* bit[3];
  node() {
    bit[0] = bit[1] = NULL;
    cnt = 0;
  }
};
node* root;
void Insertt(int x) {
  node* cur = root;
  for (int i = 28; i >= 0; --i) {
    if (cur->bit[(x >> i) & 1] == NULL) cur->bit[(x >> i) & 1] = new node();
    cur = cur->bit[(x >> i) & 1];
    ++(cur->cnt);
  }
}
void Erasee(int x) {
  node* cur = root;
  for (int i = 28; i >= 0; --i) {
    --(cur->bit[(x >> i) & 1]->cnt);
    if (cur->bit[(x >> i) & 1]->cnt == 0) {
      cur->bit[(x >> i) & 1] = NULL;
      return;
    } else
      cur = cur->bit[(x >> i) & 1];
  }
}
int Query(int p, int l) {
  int res = 0;
  node* cur = root;
  for (int i = 28; i >= 0; --i) {
    if (((l >> i) & 1) == 0) {
      if (cur->bit[(p >> i) & 1] != NULL)
        cur = cur->bit[(p >> i) & 1];
      else
        return res;
    } else {
      if (cur->bit[(p >> i) & 1] != NULL) res += cur->bit[(p >> i) & 1]->cnt;
      if (cur->bit[(1 ^ ((p >> i) & 1))] != NULL)
        cur = cur->bit[(1 ^ ((p >> i) & 1))];
      else
        return res;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  root = new node();
  for (int i = 1; i <= n; ++i) {
    int type, p, l;
    scanf("%d%d", &type, &p);
    if (type == 1) Insertt(p);
    if (type == 2) Erasee(p);
    if (type == 3) {
      scanf("%d", &l);
      printf("%d\n", Query(p, l));
    }
  }
  return 0;
}
