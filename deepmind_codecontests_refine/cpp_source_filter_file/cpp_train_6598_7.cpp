#include <bits/stdc++.h>
using namespace std;
int const oo = 1e9, bound = 1e6 + 2, mod = oo + 7, N = 6e5 + 2;
long long const OO = 1e18;
struct node {
  int next[2], pr;
  node() {
    memset(next, -1, sizeof next);
    pr = 0;
  }
};
vector<node> trie;
int res[bound];
void insert(int a) {
  int i = 0, j = 30;
  while (j > -1) {
    int b = (a >> j) & 1;
    if (trie[i].next[b] == -1) {
      trie[i].next[b] = trie.size();
      trie.push_back(node());
    }
    j--;
    trie[i].pr++;
    i = trie[i].next[b];
  }
  trie[i].pr++;
}
pair<int, int> query(int a) {
  int i = 0, j = 30, idx = 0, res = 0;
  while (j > -1) {
    int b = (a >> j) & 1;
    if (trie[i].next[!b] != -1) {
      idx |= (!b) << j;
      res |= 1 << j;
      i = trie[i].next[!b];
    } else if (trie[i].next[b] != -1) {
      idx |= b << j;
      i = trie[i].next[b];
    } else
      break;
    j--;
  }
  return {res, idx};
}
void del(int a, int i = 0, int j = 30) {
  if (j == -1) {
    trie[i].pr--;
    return;
  }
  int b = (a >> j) & 1;
  del(a, trie[i].next[b], j - 1);
  trie[i].pr--;
  if (!trie[trie[i].next[b]].pr) trie[i].next[b] = -1;
}
int main() {
  trie.push_back(node());
  int n;
  cin >> n;
  for (int(i) = 0; (i) < (n + 1); (i)++) insert(i);
  int mx = 0;
  for (int i = n; i > -1; i--) {
    pair<int, int> qq = query(i);
    res[qq.second] = i;
    mx += qq.first;
    del(qq.second);
  }
  cout << mx << endl;
  for (int(i) = 0; (i) < (n + 1); (i)++) cout << res[i] << ' ';
  return 0;
}
