#include <bits/stdc++.h>
using namespace std;
long long m[100010];
bool check(long long a, long long b) {
  if (a < b) swap(a, b);
  int gs = 0;
  m[gs++] = a;
  m[gs++] = b;
  while (b != 0) {
    m[gs++] = a % b;
    a = b;
    b = m[gs - 1];
  }
  bool flag = false;
  for (int i = gs - 2; i > 0; i--) {
    if (m[i] % 2 == 1) {
      if ((m[i - 1] / m[i]) % 2 == 0) {
        flag = true;
      } else {
        flag = !flag;
      }
    } else {
      if (m[i - 1] / m[i] == 1) {
        flag = !flag;
        continue;
      }
      if (((m[i - 1] / m[i]) % (a + 1)) % 2 == 0)
        flag = true;
      else
        flag = !flag;
    }
  }
  return flag;
}
int main() {
  int t;
  long long a, b;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%I64d%I64d", &a, &b);
    if (check(a, b))
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
