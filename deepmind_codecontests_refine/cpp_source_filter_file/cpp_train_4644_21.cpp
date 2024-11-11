#include <bits/stdc++.h>
using namespace std;
const int Q = (int)1e5 + 9, logP = 3;
int trie[Q * logP][2], cnt[Q * logP][2], tme;
void ins(int num) {
  for (int u = 0, d = logP - 1; d >= 0; --d) {
    if (!trie[u][0]) trie[u][0] = ++tme;
    if (!trie[u][1]) trie[u][1] = ++tme;
    ++cnt[u][num >> d & 1];
    u = trie[u][num >> d & 1];
  }
}
void del(int num) {
  for (int u = 0, d = logP - 1; d >= 0; --d) {
    --cnt[u][num >> d & 1];
    u = trie[u][num >> d & 1];
  }
}
bool bitP, bitL;
int qry(int num, int l) {
  int ans = 0;
  for (int u = 0, d = logP - 1; d >= 0; --d) {
    if (u == 0 && d != logP - 1) break;
    bitP = num >> d & 1, bitL = l >> d & 1;
    if (bitL) {
      if (bitP) {
        ans += cnt[u][1];
        u = trie[u][0];
      } else {
        ans += cnt[u][0];
        u = trie[u][1];
      }
    } else {
      if (bitP)
        u = trie[u][1];
      else
        u = trie[u][0];
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, type, p, l;
  cin >> q;
  while (q-- > 0) {
    cin >> type >> p;
    if (type == 1) {
      ins(p);
      continue;
    }
    if (type == 2) {
      del(p);
      continue;
    }
    cin >> l;
    cout << qry(p, l) << '\n';
  }
}
