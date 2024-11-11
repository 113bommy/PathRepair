#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000 + 17;
const long long INF = 1e9 + 17;
int n, u[10], x, Sum;
void print() {
  for (int i = 9; i >= 0; --i)
    for (int j = 1; j <= u[i]; ++j) printf("%d", i);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x), u[x]++, Sum += x;
  if (!u[0]) printf("-1"), exit(0);
  if (Sum == 0) printf("0"), exit(0);
  if (Sum % 3 == 0) {
    print();
    exit(0);
  }
  for (int i = 1; i <= 9; ++i) {
    if (u[i] && (Sum - i) % 3 == 0 && Sum - i > 0) {
      u[i]--;
      print();
      exit(0);
    }
  }
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j < i; ++j) {
      if (u[i] && u[j] && (Sum - i - j) % 3 == 0 && Sum - i - j > 0) {
        u[i]--;
        u[j]--;
        print();
        exit(0);
      }
    }
    if (u[i] >= 2 && (Sum - i) % 3 == 0 && Sum - i * 2 > 0) {
      u[i]--;
      print();
      exit(0);
    }
  }
  if (u[0])
    printf("0");
  else
    printf("-1");
  return 0;
}
