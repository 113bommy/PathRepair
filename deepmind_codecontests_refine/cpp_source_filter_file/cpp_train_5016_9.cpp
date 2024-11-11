#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200010;
int n, k, P[Maxn], Q[Maxn], Ref[Maxn];
int A[Maxn], Ans[Maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &P[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &Q[i]);
  for (int i = 1; i <= n; ++i) Ref[P[i]] = i;
  for (int i = 1; i < n; ++i)
    if (Ref[Q[i + 1]] < Ref[Q[i]]) ++A[Ref[Q[i + 1]]], --A[Ref[Q[i]]];
  int Sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (Sum)
      Ans[i] = Ans[i - 1];
    else
      Ans[i] = Ans[i - 1] + 1;
    Sum += A[i];
  }
  if (Ans[n] < k)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%c", Ans[Ref[i]] + 'a' - 1);
    printf("\n");
  }
  return 0;
}
