#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
struct st {
  int next[2], mn;
  st() {
    next[0] = next[1] = 0;
    mn = 1e9;
  }
};
int q;
vector<st> t[N];
st temp;
void add(int v, int k) {
  int cur = 0;
  for (int i = 17; i >= 0; i--) {
    int c = (((1 << i) & v) != 0);
    if (t[k][cur].next[c] == 0) {
      t[k][cur].next[c] = t[k].size();
      t[k].push_back(temp);
    }
    cur = t[k][cur].next[c];
    t[k][cur].mn = min(t[k][cur].mn, v);
  }
}
int get(int x, int s, int k) {
  int v = 0;
  for (int i = 17; i >= 0; i--) {
    if ((1 << i) & x) {
      if (t[k][t[k][v].next[0]].mn <= s)
        v = t[k][v].next[0];
      else
        v = t[k][v].next[1];
    } else {
      if (t[k][t[k][v].next[1]].mn <= s)
        v = t[k][v].next[1];
      else
        v = t[k][v].next[0];
    }
    if (t[k][v].mn > s || v == 0) return -1;
  }
  return t[k][v].mn;
}
int main() {
  for (int i = 0; i <= 1e5; i++) t[i].push_back(temp);
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int v;
      scanf("%d", &v);
      for (int i = 1; i * i <= v; i++) {
        if (v % i == 0) {
          add(v, i);
          add(v, v / i);
        }
      }
    } else {
      int x, s, k;
      scanf("%d %d %d", &x, &k, &s);
      if (x % k != 0) {
        puts("-11");
      } else {
        printf("%d\n", get(x, s - x, k));
      }
    }
  }
}
