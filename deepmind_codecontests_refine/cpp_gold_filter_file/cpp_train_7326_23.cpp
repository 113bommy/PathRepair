#include <bits/stdc++.h>
using namespace std;
struct node {
  int next[2];
} non;
vector<long long int> a;
vector<node> trie;
int L = 39;
void add(long long int num) {
  int cur_node = 0;
  for (int i = L; i >= 0; i--) {
    long long int bit = (num >> i) & 1;
    if (trie[cur_node].next[bit] == -1) {
      trie[cur_node].next[bit] = trie.size();
      trie.push_back(non);
    }
    cur_node = trie[cur_node].next[bit];
  }
}
long long int find(long long int num) {
  int cur_node = 0;
  long long int res = 0ll;
  for (int i = L; i >= 0; i--) {
    long long int bit = (num >> i) & 1;
    if (trie[cur_node].next[1 - bit] != -1) {
      res += (1ll << i);
      cur_node = trie[cur_node].next[1 - bit];
    } else
      cur_node = trie[cur_node].next[bit];
  }
  return res;
}
int main() {
  int n, i;
  non.next[0] = non.next[1] = -1;
  trie.push_back(non);
  long long int sum = 0ll, pre = 0ll, ans = 0ll;
  scanf("%d", &n);
  a.assign(n, 0ll);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum ^= a[i];
    ans = max(ans, sum);
  }
  for (i = 0; i < n; i++) {
    pre ^= a[i];
    ans = max(ans, sum ^ pre);
    add(pre);
    ans = max(ans, find(sum ^ pre));
  }
  printf("%lld", ans);
}
