#include <bits/stdc++.h>
using namespace std;
int Trie[5700100][2];
bool mark[300010];
int cnt = 0;
int N, M;
int bits(int x, int i) { return (x >> i) & 1; }
void Add(int T) {
  int node = 0;
  for (int i = 19; i >= 0; --i) {
    int x = bits(T, i);
    if (Trie[node][x] == 0) Trie[node][x] = ++cnt;
    node = Trie[node][x];
  }
}
void get(int T, int &res) {
  int node = 0;
  for (int i = 19; i >= 0; --i) {
    int x = bits(T, i);
    if (Trie[node][x] != 0) {
      node = Trie[node][x];
    } else {
      res += (1 << i);
      node = Trie[node][1 - x];
    }
  }
  cout << res << '\n';
}
void nhap() {
  int x;
  cin >> N >> M;
  while (N--) {
    cin >> x;
    mark[x] = true;
  }
  for (int i = 0; i <= 300000; ++i)
    if (!mark[i]) Add(i);
  int T = 0, res;
  while (M--) {
    res = 0;
    cin >> x;
    T = T ^ x;
    get(T, res);
  }
}
int main() {
  nhap();
  return 0;
}
