#include <bits/stdc++.h>
using namespace std;
bool solve(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return 0;
  bool bad = solve(a, b % a);
  if (!bad) return 1;
  long long moves = b / a - 1;
  if (a % 2) return moves % 2;
  moves %= (a + 1);
  if (moves == a) return 1;
  return moves % 2;
}
int main() {
  int test_num;
  long long a, b;
  scanf("%d", &test_num);
  for (; test_num--;) {
    scanf("%I64d%I64d", &a, &b);
    if (solve(a, b))
      puts("First");
    else
      puts("Second");
  }
  return 0;
}
