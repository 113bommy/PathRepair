#include <bits/stdc++.h>
using namespace std;
int n, a[300005], b[300005];
int trie[33 * 300005][2];
int cnt[33 * 300005];
int num = 0;
void push(int v) {
  int cur = 0;
  for (int i = 30; i >= 0; i--) {
    int bit = (v >> i) & 1;
    if (trie[cur][bit] == -1) {
      trie[cur][bit] = ++num;
    }
    cnt[trie[cur][bit]]++;
    cur = trie[cur][bit];
  }
}
void findLex(int v) {
  int ans = 0, cur = 0;
  for (int i = 30; i >= 0; i--) {
    int bit = (v >> i) & 1;
    if (cnt[trie[cur][bit]] > 0) {
      bit = 1 - bit;
    }
    ans |= (bit << i);
    cnt[trie[cur][bit]]--;
    cur = trie[cur][bit];
  }
  printf("%d ", ans ^ v);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  memset(trie, -1, sizeof(trie));
  for (int i = 0; i < n; i++) {
    push(b[i]);
  }
  for (int i = 0; i < n; i++) {
    findLex(a[i]);
  }
  printf("\n");
}
