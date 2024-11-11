#include <bits/stdc++.h>
using namespace std;
int que = 0;
pair<int, int> ask(int i) {
  ++que;
  printf("? %d\n", i + 1);
  fflush(stdout);
  int v, ne;
  scanf("%d %d", &v, &ne);
  if (ne != -1) --ne;
  return {v, ne};
};
int main() {
  int n, start, x;
  scanf("%d %d %d", &n, &start, &x);
  --start;
  int sq = 240;
  map<int, int> q;
  for (int i = 0; i < n; i += sq) {
    int fin = min(n - 1, i + sq - 1);
    int len = fin - i + 1;
    set<int> used;
    for (int j = 0; j < min(4, len); ++j) {
      int pos = rand() % len;
      int cnt = 0;
      while (used.count(pos) && (cnt++) < 40) pos = rand() % len;
      pos += i;
      auto pa = ask(pos);
      used.insert(pos);
      q[pa.first] = pa.second;
    }
  }
  pair<int, int> pa = {0, 0};
  int pp = -1;
  for (auto it : q) {
    if (it.first == x) {
      printf("! %d\n", it.first);
      return 0;
    }
    if (it.first > x) {
      break;
    }
    pp = it.second;
  }
  if (pp == -1) pp = start;
  while (pp != -1) {
    pa = ask(pp);
    if (pa.first >= x) {
      printf("! %d\n", pa.first);
      return 0;
    }
    pp = pa.second;
  }
  printf("! -1\n");
  return 0;
}
