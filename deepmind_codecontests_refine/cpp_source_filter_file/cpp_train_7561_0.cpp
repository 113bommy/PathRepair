#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667177216")
using namespace std;
const long long MOD = 1000000000 + 7;
const long long MAXN = 1000000 + 10;
struct node {
  node* c[2];
  int count;
};
void insert_number(node* v, int number, int pos) {
  v->count++;
  if (pos < 0) return;
  int cur = (number & (1 << pos)) >> pos;
  if (!v->c[cur]) {
    v->c[cur] = new node();
  }
  insert_number(v->c[cur], number, pos - 1);
}
int resolve(node* v, int number, int pos) {
  v->count--;
  if (pos < 0) return number;
  int nxt = (number & (1 << pos)) >> pos;
  if (!v->c[nxt] || v->c[nxt]->count == 0) {
    nxt ^= 1;
  }
  int new_number = resolve(v->c[nxt], number, pos - 1);
  new_number ^= (nxt << pos);
  return new_number;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  vector<int> a(n), p(n);
  for (int(i) = 0; (i) < n; (i)++) scanf("%d", &a[i]);
  for (int(i) = 0; (i) < n; (i)++) scanf("%d", &p[i]);
  node* root = new node();
  for (int(i) = 0; (i) < n; (i)++) insert_number(root, p[i], 5);
  for (int i = 0; i < n; ++i) {
    printf("%d ", resolve(root, a[i], 5));
  }
  return 0;
}
