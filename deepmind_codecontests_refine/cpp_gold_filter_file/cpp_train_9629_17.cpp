#include <bits/stdc++.h>
using namespace std;
vector<int> gr[500 * 1000 + 10];
vector<int> dep[500 * 1000 + 10];
char s[500 * 1000 + 10];
int depthx[500 * 1000 + 10];
int in[500 * 1000 + 10], out[500 * 1000 + 10];
int timex = 1;
void dfstime(int v, int d) {
  in[v] = timex++;
  for (int i = 0; i < (int)gr[v].size(); ++i) {
    int to = gr[v][i];
    dep[d].push_back(to);
    depthx[to] = d;
    dfstime(to, d + 1);
  }
  out[v] = timex++;
}
bool isOk(int v, int pr) { return in[pr] < in[v] && out[pr] > out[v]; }
bool isLeft(int v, int pr) { return out[v] < in[pr]; }
map<pair<int, int>, int> mem;
int let[26];
void run(int h, int v) {
  int l = 0, r = (int)dep[h].size() - 1;
  int left = -1;
  while (l <= r) {
    int m = l + r >> 1;
    if (isOk(dep[h][m], v)) {
      left = m;
      r = m - 1;
    } else if (isLeft(dep[h][m], v)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if (left == -1) {
    mem[make_pair(h, v)] = 1;
    puts("Yes");
    return;
  }
  int right = -1;
  l = 0;
  r = (int)dep[h].size() - 1;
  while (l <= r) {
    int m = l + r >> 1;
    if (isOk(dep[h][m], v)) {
      right = m;
      l = m + 1;
    } else if (isLeft(dep[h][m], v)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if (right == -1) {
    mem[make_pair(h, v)] = 1;
    puts("Yes");
    return;
  }
  memset(let, 0, sizeof(let));
  for (int k = left; k <= right; ++k) {
    int vnum = dep[h][k];
    let[s[vnum] - 'a']++;
  }
  int x = 0;
  for (int i = 0; i < 26; ++i) {
    x += let[i] & 1;
  }
  if (x <= 1) {
    mem[make_pair(h, v)] = 1;
    puts("Yes");
  } else {
    mem[make_pair(h, v)] = -1;
    puts("No");
  }
}
int main() {
  int totvertex, totqueries;
  scanf("%d %d", &totvertex, &totqueries);
  for (int i = 1; i < totvertex; ++i) {
    int v;
    scanf("%d", &v);
    v--;
    gr[v].push_back(i);
  }
  scanf("%s", s);
  dfstime(0, 1);
  for (int i = 0; i < totqueries; ++i) {
    int v, h;
    scanf("%d %d", &v, &h);
    v--;
    h--;
    if (depthx[v] >= h) {
      puts("Yes");
      continue;
    }
    int x = mem[make_pair(h, v)];
    if (x == 1) {
      puts("Yes");
      continue;
    }
    if (x == -1) {
      puts("No");
      continue;
    }
    run(h, v);
  }
  return 0;
}
