#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, n, ans = 0;
  scanf("%d%d%d", &h, &m, &n);
  vector<int> v(h, -1);
  char ch;
  int id, hash;
  unordered_map<int, int> um;
  for (int i = 0; i < n; ++i) {
    scanf("%c %d", &ch, &id);
    if (ch == '+') {
      scanf("%d", &hash);
      while (v[hash] != -1) {
        hash += m;
        hash %= h;
        ++ans;
      }
      v[hash] = id;
      um[id] = hash;
    } else if (ch == '-') {
      v[um[id]] = -1;
    }
  }
  printf("%d", ans);
}
