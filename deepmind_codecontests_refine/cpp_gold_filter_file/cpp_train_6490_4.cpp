#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128777216")
using namespace std;
struct Basket {
  int id;
  int val;
  void init(int i, int n) {
    this->id = i + 1;
    val = abs((n + 1) - (i + 1) * 2);
  }
  bool operator<(const Basket &b) const {
    return val < b.val || val == b.val && id < b.id;
  }
} b[100100];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    b[i].init(i, m);
  }
  sort(b, b + m);
  for (int i = 0; i < n; i++) {
    printf("%d\n", b[i % m].id);
  }
  return 0;
}
