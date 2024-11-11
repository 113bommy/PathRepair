#include <bits/stdc++.h>
using namespace std;
int N, P, K;
bool use[200000];
struct Ord {
  int a, b, no;
  Ord() {}
  Ord(int _a, int _b, int _no) {
    a = _a;
    b = _b;
    no = _no;
  }
} ord[200000];
bool cmp1(Ord p1, Ord p2) { return p1.b > p2.b || p1.b == p2.b && p1.a < p2.a; }
bool cmp2(Ord p1, Ord p2) { return p1.a > p2.a || p1.a == p2.a && p1.b < p2.b; }
int main() {
  scanf("%d %d %d", &N, &P, &K);
  for (int Ni = 0; Ni < N; Ni++) {
    int _a, _b;
    scanf("%d %d", &_a, &_b);
    ord[Ni] = Ord(_a, _b, Ni + 1);
  }
  sort(ord, ord + N, cmp1);
  bool flag = false;
  sort(ord, ord + N - P + K, cmp2);
  int _i = 0;
  for (int Ki = 0; Ki < K; Ki++) {
    if (flag) printf(" ");
    flag = true;
    printf("%d", ord[Ki].no);
    use[ord[Ki].no] = true;
    if (ord[Ki].b < ord[_i].b ||
        ord[Ki].b == ord[_i].b && ord[Ki].a > ord[_i].a)
      _i = Ki;
  }
  int _a = ord[_i].a, _b = ord[_i].b;
  int cnt = K;
  sort(ord, ord + N, cmp1);
  for (int Ni = 0; Ni < N; Ni++) {
    if (use[ord[Ni].no]) continue;
    if (cnt == P) break;
    if (ord[Ni].b < _b || ord[Ni].b == _b && ord[Ni].a > ord[_i].a) {
      if (flag) printf(" ");
      flag = true;
      printf("%d", ord[Ni].no);
      use[ord[Ni].no] = true;
      cnt++;
    }
  }
  puts("");
}
