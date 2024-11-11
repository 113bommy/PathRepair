#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], p;
struct trie {
  struct trie *child[3];
  int cnt[3];
};
struct trie *getNode() {
  struct trie *node = new trie;
  for (int i = 0; i < 2; i++) {
    node->cnt[i] = 0;
    node->child[i] = NULL;
  }
  return node;
}
void insert(struct trie *root, int key) {
  struct trie *crawl = root;
  bool bi;
  for (int i = 30; i >= 0; i--) {
    bi = ((1 << i) & key);
    if (crawl->child[bi] == NULL) crawl->child[bi] = getNode();
    crawl->cnt[bi]++;
    crawl = crawl->child[bi];
  }
}
int search(struct trie *root, int key) {
  struct trie *crawl = root;
  int ret = 0;
  bool bi;
  for (int i = 30; i >= 0; i--) {
    bi = ((1 << i) & key);
    if (crawl->child[bi] != NULL && crawl->cnt[bi] > 0) {
      ret += (1 << i) * bi;
      crawl->cnt[bi]--;
      crawl = crawl->child[bi];
    } else {
      ret += (1 << i) * (1 - bi);
      crawl->cnt[1 - bi]--;
      crawl = crawl->child[1 - bi];
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  struct trie *root = getNode();
  for (int i = 0; i < n; i++) {
    cin >> p;
    insert(root, p);
  }
  int num;
  for (int i = 0; i < n; i++) {
    num = search(root, a[i]);
    if (i > 0) cout << " ";
    cout << (num | a[i]) - (num & a[i]);
  }
  cout << endl;
  return 0;
}
