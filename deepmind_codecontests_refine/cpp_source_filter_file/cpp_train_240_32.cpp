#include <bits/stdc++.h>
using namespace std;
long long n, A, B;
const long long N = 110;
long long sg[N];
bool dfs(long long A, long long B) {
  if (A > B) swap(A, B);
  if (A == 1) return true;
  if (A == 0) return false;
  bool ok = dfs(B % A, A);
  if (!ok)
    return true;
  else {
    long long s = B / A;
    if (A & 1) {
      if (s & 1)
        return true;
      else
        return false;
    } else {
      s %= (A + 1);
      if (s & 1) return false;
      return true;
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T) {
    T--;
    scanf("%I64d%I64d", &A, &B);
    if (dfs(A, B))
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
