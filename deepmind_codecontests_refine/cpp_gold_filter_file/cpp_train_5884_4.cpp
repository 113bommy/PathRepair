#include <bits/stdc++.h>
using namespace std;
inline long long answer(long long val) {
  if (!val) return 0;
  long long i, j, sol = 0, val2 = 1;
  for (i = 1; (val2 << i) <= val; i++) sol += i - 1;
  for (j = i - 2; j >= 0 && ((val2 << j) & val); j--) sol++;
  if (j > -1 && (((val2 << j) - 1) & val) == ((val2 << j) - 1)) sol++;
  return sol;
}
long long a, b;
int main() {
  scanf("%I64d%I64d", &a, &b);
  printf("%I64d\n", answer(b) - answer(a - 1));
  return 0;
}
