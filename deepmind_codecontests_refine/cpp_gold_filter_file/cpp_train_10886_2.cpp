#include <bits/stdc++.h>
using namespace std;
char s[200001], p[200001];
set<char> se;
int main() {
  int n, i, ret = 1;
  p['L'] = 'R';
  p['R'] = 'L';
  p['U'] = 'D';
  p['D'] = 'U';
  scanf("%d %s", &n, s);
  for (i = 0; i < n; i++) {
    se.insert(s[i]);
    if (se.size() == 3 || se.find(p[s[i]]) != se.end()) {
      se.clear();
      se.insert(s[i]);
      ret++;
    }
  }
  printf("%d", ret);
  return 0;
}
