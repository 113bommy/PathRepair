#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
int print_value(A title, B val) {
  cout << title << " = " << val << "\n";
  return 1;
}
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename A>
int logg(A v) {
  cout << v << "\n";
  return 0;
}
void read_intq(int &r) {
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') return;
    r = r * 10 + (c - '0');
  }
}
void read_llq(long long &r) {
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') return;
    r = r * 10 + (c - '0');
  }
}
char get_char() {
  char c;
  while (1) {
    c = getchar();
    if (c != '\n' && c != ' ') return c;
  }
}
void run();
int main() {
  srand(time(NULL));
  do {
    run();
    if (0) {
      0 ? printf("-------------------------------\n") : 0;
      0 ? printf("-------------------------------\n") : 0;
    }
  } while (0);
  return 0;
}
struct point {
  int x, y;
  int m;
  int idx;
  bool operator<(const point &p) const {
    if (m & 1)
      return x < p.x;
    else
      return x > p.x;
  }
};
int dist(point &p1, point &p2) { return abs(p1.x - p2.x) + abs(p1.y - p2.y); }
priority_queue<point> q[1004];
void run() {
  int n;
  scanf("%d", &n);
  point p;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p.x, &p.y);
    p.m = p.x / 1000;
    p.idx = i + 1;
    q[p.m].push(p);
  }
  for (int i = 0; i < 1001; i++) {
    while (!q[i].empty()) {
      printf("%d", q[i].top().idx);
      putchar(' ');
      q[i].pop();
    }
  }
  putchar('\n');
}
