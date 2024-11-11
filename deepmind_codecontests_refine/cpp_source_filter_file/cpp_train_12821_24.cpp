#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
struct Node {
  int a;
  int b;
  int c;
  int d;
};
std::vector<Node> vec;
int a[1010], b[1010], p1[1010], p2[1010], _p1[1010], _p2[1010], _a[1010],
    _b[1010];
int main() {
  int n = inp();
  for (int i = 1; i <= n; i++) {
    a[i] = inp();
    _a[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = inp();
    _b[b[i]] = i;
  }
  for (int i = 1; i <= n; i++) p1[i] = p2[i] = _p1[i] = _p2[i] = i;
  for (int i = 1; i <= n; i++) {
    if (i == _p1[_a[i]] && i == _p2[_b[i]]) continue;
    vec.push_back((Node){i, _p1[_a[i]], _p2[_b[i]], i});
    int f1 = p1[i];
    int f2 = p2[i];
    std::swap(p1[i], p1[_p1[_a[i]]]);
    std::swap(p2[i], p2[_p2[_b[i]]]);
    std::swap(_p1[_a[i]], _p1[f1]);
    std::swap(_p2[_b[i]], _p2[f2]);
  }
  printf("%d\n", (int)(vec.size()));
  for (int i = 0; i < vec.size(); i++)
    printf("%d %d %d %d\n", vec[i].a, vec[i].b, vec[i].c, vec[i].d);
}
