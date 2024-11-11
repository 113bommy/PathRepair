#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int trie[1001000][3];
int cnt[1001000];
int v[25];
char s[25];
int nodeCnt;
int addNode() {
  memset(trie[nodeCnt], -1, sizeof trie[nodeCnt]);
  return nodeCnt++;
}
void add(int flag) {
  int cur = 0;
  for (int i = 0; i < int(22); i++) {
    int &nxt = trie[cur][v[i]];
    if (nxt == -1) nxt = addNode();
    cur = nxt;
    if (flag)
      cnt[cur]++;
    else
      cnt[cur]--;
  }
}
int query() {
  int cur = 0;
  for (int i = 0; i < int(22); i++) {
    int x = s[i] - '0';
    int &nxt = trie[cur][x];
    if (nxt == -1) return 0;
    cur = nxt;
  }
  return cnt[cur];
}
void parse(long long val) {
  for (int i = 0; i < int(22); i++) {
    int x = val % 10;
    val /= 10;
    if (x & 1)
      v[i] = 1;
    else
      v[i] = 0;
  }
}
int main() {
  addNode();
  int t;
  long long x;
  char c;
  scanf("%d", &t);
  while (t--) {
    scanf(" %c ", &c);
    if (c == '+' || c == '-') {
      scanf("%I64d", &x);
      parse(x);
      add(c == '+');
    } else {
      scanf("%s", s);
      int len = strlen(s);
      reverse(s, s + len);
      for (int i = int(len); i <= int(22); i++) s[i] = '0';
      printf("%d\n", query());
    }
  }
  return 0;
}
