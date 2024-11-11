#include <bits/stdc++.h>
using namespace std;
bool gao(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return false;
  if (!gao(b % a, a)) return true;
  return b / a % (a + 3) % 2 == 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    puts(gao(a, b) ? "First" : "Second");
  }
}
