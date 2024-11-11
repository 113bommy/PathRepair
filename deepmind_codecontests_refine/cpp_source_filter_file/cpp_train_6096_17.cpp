#include <bits/stdc++.h>
using namespace std;
struct Rectangle {
  int i1, j1, i2, j2;
  bool inside(Rectangle &r) {
    if (r.i1 <= i1 && i2 <= r.i2)
      if (r.j1 <= j1 && j2 <= r.j2) return true;
    return false;
  }
};
int ask(Rectangle r) {
  printf("? %d %d %d %d\n", r.i1 + 1, r.j1 + 1, r.i2 + 1, r.j2 + 1);
  fflush(stdout);
  int q;
  scanf("%d", &q);
  return q;
}
void print(vector<Rectangle> V) {
  printf("!");
  for (Rectangle r : V) {
    printf(" %d %d %d %d", r.i1 + 1, r.j1 + 1, r.i2 + 1, r.j2 + 1);
  }
  printf("\n");
  fflush(stdout);
}
Rectangle findRect(int N, vector<Rectangle> V) {
  Rectangle r = {0, 0, N - 1, N - 1};
  {
    int lo = 0, hi = N - 1;
    while (lo < hi) {
      int m = (lo + hi) / 2;
      r.j2 = m;
      int e = ask(r);
      for (int i = 0; i < V.size(); ++i) {
        if (V[i].inside(r)) e--;
      }
      if (e == 0) {
        lo = m + 1;
      } else {
        hi = m;
      }
    }
    r.j2 = lo;
  }
  {
    int lo = 0, hi = r.j2;
    while (lo < hi) {
      int m = (lo + hi + 1) / 2;
      r.j1 = m;
      int e = ask(r);
      for (int i = 0; i < V.size(); ++i) {
        if (V[i].inside(r)) e--;
      }
      if (e == 0) {
        hi = m - 1;
      } else {
        lo = m;
      }
    }
    r.j1 = lo;
  }
  {
    int lo = 0, hi = N - 1;
    while (lo < hi) {
      int m = (lo + hi) / 2;
      r.i2 = m;
      int e = ask(r);
      for (int i = 0; i < V.size(); ++i) {
        if (V[i].inside(r)) e--;
      }
      if (e == 0) {
        lo = m + 1;
      } else {
        hi = m;
      }
    }
    r.i2 = lo;
  }
  {
    int lo = 0, hi = r.i2;
    while (lo < hi) {
      int m = (lo + hi + 1) / 2;
      r.i2 = m;
      int e = ask(r);
      for (int i = 0; i < V.size(); ++i) {
        if (V[i].inside(r)) e--;
      }
      if (e == 0) {
        hi = m - 1;
      } else {
        lo = m;
      }
    }
    r.i1 = lo;
  }
  return r;
}
int main() {
  int N;
  cin >> N;
  vector<Rectangle> V;
  V.push_back(findRect(N, V));
  V.push_back(findRect(N, V));
  print(V);
}
