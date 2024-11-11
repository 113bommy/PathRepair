#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, M;
  scanf("%d %d", &A, &B);
  scanf("%d", &M);
  long long p = 1000000000 % M;
  bool ok = false;
  for (int x = 0; x < M && x <= A; ++x) {
    long long h = p * x % M;
    if (h == 0) continue;
    if (M - h <= B) continue;
    ok = true;
    printf("1 %09d\n", x);
    break;
  }
  if (!ok) puts("2");
}
