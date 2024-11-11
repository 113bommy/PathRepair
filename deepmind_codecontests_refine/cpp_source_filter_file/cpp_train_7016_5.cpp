#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > sp;
set<int> x;
set<int> y;
void read() {
  for (int i = 0; i < 8; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    x.insert(u);
    y.insert(v);
    sp.insert(make_pair(u, v));
  }
}
bool solve() {
  if (x.size() != 3) return false;
  if (y.size() != 3) return false;
  set<int>::iterator t;
  t = x.begin();
  int X[3], Y[3];
  for (int i = 0; i < 3; i++) {
    X[i] = *t;
    t++;
  }
  t = y.begin();
  for (int i = 0; i < 3; i++) {
    Y[i] = *t;
    t++;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != 1 || j != 1) {
        if (sp.count(make_pair(X[i], Y[j])) == 0) return false;
      }
    }
  }
  return true;
}
void write() { puts(solve() ? "respectabl" : "ugly"); }
int main() {
  read();
  write();
  return 0;
}
