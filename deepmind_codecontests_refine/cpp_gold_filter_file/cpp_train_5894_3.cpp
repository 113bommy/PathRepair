#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int base = 1e9 + 7;
struct trie {
  int cnt;
  int a[2];
  int& operator[](int i) { return a[i]; }
  trie() {
    a[0] = 0;
    a[1] = 0;
    cnt = 0;
  }
};
vector<trie> a;
int n, f[N], x, m, y;
int getbit(int x, int i) { return (x >> i) & 1; }
void add(int x) {
  int pos = 0;
  for (int i = 20; i >= 0; i--) {
    int bt = getbit(x, i);
    if (a[pos][bt] == 0) {
      a.push_back(trie());
      a[pos][bt] = a.size() - 1;
    }
    pos = a[pos][bt];
    a[pos].cnt++;
  }
}
int sol(int x) {
  int pos = 0;
  int res = 0;
  for (int i = 20; i >= 0; i--) {
    int bt = getbit(x, i);
    int tmp = a[pos][bt];
    if (a[tmp].cnt < (1 << i))
      pos = tmp;
    else {
      res |= (1 << i);
      pos = a[pos][1 - bt];
    }
    if (!pos) break;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  a.push_back(trie());
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (f[x] == 0) add(x);
    f[x] = 1;
  }
  y = 0;
  for (int i = 1; i <= m; i++) {
    cin >> x;
    y = y ^ x;
    cout << sol(y) << '\n';
  }
  return 0;
}
