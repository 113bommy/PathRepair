#include <bits/stdc++.h>
using namespace std;
struct Node {
  Node *next[2];
  int freq;
  Node() {
    next[0] = next[1] = NULL;
    freq = 0;
  }
} * Trie;
const int N = 1e5, B = 30;
int n, a[N], k;
void insert(int n) {
  Node *cur = Trie;
  for (int i = B - 1; i >= 0; --i) {
    int b = (n >> i) & 1;
    if (cur->next[b] == NULL) cur->next[b] = new Node();
    cur = cur->next[b];
    ++cur->freq;
  }
}
long long DFS(Node *cur, int n, int p) {
  if (cur == NULL) return 0;
  if (p == -1) return cur->freq;
  int b = (n >> p) & 1, need = (k >> p) & 1;
  long long res = 0;
  if (need == 1)
    res += DFS(cur->next[b ^ 1], n, p - 1);
  else {
    res += DFS(cur->next[b], n, p - 1);
    if (cur->next[b ^ 1] != NULL) res += cur->next[b ^ 1]->freq;
  }
  return res;
}
int main(int argc, char **argv) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  long long res = 0;
  Trie = new Node();
  insert(0);
  int xr = 0;
  for (int i = 0; i < n; ++i) {
    xr ^= a[i];
    insert(xr);
    res += DFS(Trie, xr, B - 1);
  }
  printf("%lld\n", res);
  return 0;
}
