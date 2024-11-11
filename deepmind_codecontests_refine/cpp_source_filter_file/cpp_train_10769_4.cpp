#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 500;
list<int> a, b;
int ta[maxn], tb[maxn];
char str[maxn];
const double eps = 1e-6;
void input(list<int> &x) {
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) x.push_back(str[i] - '0');
}
void init() {
  int dis = abs((int)a.size() - (int)b.size());
  list<int> *f;
  if ((int)a.size() < (int)b.size())
    f = &a;
  else
    f = &b;
  for (int i = 0; i < dis; ++i) f->push_front(0);
}
void read(list<int> &x, int *arr) {
  list<int>::iterator it = x.end();
  it--;
  int ptr = 0;
  while (1) {
    int end = 0;
    if (it == x.begin()) end = 1;
    arr[ptr++] = *it;
    if (end)
      break;
    else
      it--;
  }
}
int solve() {
  for (int i = 2e5; i >= 2; --i) {
    if (ta[i] == tb[i]) continue;
    int *big = &ta[i], *small = &tb[i];
    if (ta[i] < tb[i]) swap(big, small);
    if (*big - *small >= 2) {
      if (big == ta)
        return 1;
      else
        return -1;
    } else {
      int loss = *big - *small;
      big--, *big += loss, big--, *big += loss;
    }
  }
  double p = (1 + sqrt(5)) / 2.0;
  double up = ta[0] + ta[1] * p;
  double down = tb[0] + tb[1] * p;
  if (fabs(up - down) <= eps)
    return 0;
  else if (up > down)
    return 1;
  return -1;
}
int main(int argc, char *argv[]) {
  input(a);
  input(b);
  init();
  read(a, ta);
  read(b, tb);
  int res = solve();
  if (res == 1)
    printf(">\n");
  else if (res == 0)
    printf("=\n");
  else
    printf("<\n");
  return 0;
}
