#include <bits/stdc++.h>
using namespace std;
int trie[100005][30];
bool win[100005], lose[100005];
long long size = 1;
void insert(string a) {
  long long i, v = 0;
  for (i = 0; i < a.size(); i++) {
    if (trie[v][a[i] - 'a'] == -1) {
      trie[v][a[i] - 'a'] = size;
      size++;
    }
    v = trie[v][a[i] - 'a'];
  }
}
void nimbify() {
  int v = size - 1, i;
  bool isLeaf;
  for (v = size - 1; v >= 0; v--) {
    isLeaf = true;
    for (i = 0; i < 27; i++) {
      if (trie[v][i] != -1) {
        win[v] |= (!win[trie[v][i]]);
        lose[v] |= (!lose[trie[v][i]]);
        isLeaf = false;
      }
    }
    if (isLeaf) {
      win[v] = false;
      lose[v] = true;
    }
  }
  return;
}
int main() {
  long long n, k, i, j;
  cin >> n >> k;
  for (i = 0; i < 100005; i++) {
    for (j = 0; j < 30; j++) {
      trie[i][j] = -1;
      win[i] = false;
      lose[i] = false;
    }
  }
  string a;
  for (i = 0; i < n; i++) {
    cin >> a;
    insert(a);
  }
  nimbify();
  if (win[0] && lose[0]) {
    cout << "First";
  } else if (win[0] && !lose[0]) {
    (k % 2) ? cout << "First" : cout << "Second";
  } else {
    cout << "Second";
  }
  return 0;
}
