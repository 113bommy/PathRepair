#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MX = 1e6 + 7;
int n, k;
long long ans;
int Xor[MX];
struct node {
  int cnt;
  node *next[2];
  node() {
    cnt = 0;
    next[0] = next[1] = NULL;
  }
} * trie;
void insert(int x) {
  node *head = trie;
  for (int i = 31; i >= 0; --i) {
    int flag = (x >> i) & 1;
    if (head->next[flag] == NULL) head->next[flag] = new node;
    head = head->next[flag];
    head->cnt++;
  }
}
void dfs(node *head, int j, int bit) {
  if (head == NULL) return;
  if (bit == -1) {
    ans += head->cnt;
    return;
  }
  int bk = (k >> bit) & 1;
  int bj = (j >> bit) & 1;
  if (bk == 0 && bj == 0) {
    if (head->next[1]) ans += head->next[1]->cnt;
    dfs(head->next[0], j, bit - 1);
  } else if (bk == 0 && bj == 1) {
    if (head->next[0]) ans += head->next[0]->cnt;
    dfs(head->next[1], j, bit - 1);
  } else if (bk == 1 && bj == 1) {
    dfs(head->next[0], j, bit - 1);
  } else if (bk == 1 && bj == 0) {
    dfs(head->next[1], j, bit - 1);
  }
}
int main() {
  trie = new node;
  int n;
  cin >> n >> k;
  Xor[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> Xor[i];
    Xor[i] ^= Xor[i - 1];
  }
  insert(0);
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    insert(Xor[i]);
    dfs(trie, Xor[i], 31);
  }
  cout << ans << endl;
  return 0;
}
