#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const unsigned long long mod = 1000000007;
long long Inf = (long long)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;
void print_and_flush(long long idx) {
  printf("? %I64d\n", idx);
  fflush(stdout);
}
void printf_ans(int val) {
  printf("! %d", val);
  fflush(stdout);
  exit(0);
}
int main() {
  int n, s, x;
  scanf("%d%d%d", &n, &s, &x);
  int l = s;
  print_and_flush(s);
  int next, val;
  scanf("%d%d", &val, &next);
  int mn = val;
  if (val >= x) {
    printf_ans(val);
  }
  srand(time(0));
  for (int i = 0; i < 1000; i++) {
    long long xx = (rand() + rand()) % n + 1;
    print_and_flush(xx);
    scanf("%d%d", &val, &next);
    if (val > mn && val <= x) {
      mn = val;
      l = xx;
    }
  }
  for (int i = 0; i < 999; i++) {
    print_and_flush(l);
    scanf("%d%d", &val, &next);
    l = next;
    if (val >= x) {
      printf_ans(val);
    }
    if (next == -1) printf_ans(-1);
  }
  printf_ans(-1);
  return 0;
}
