#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
int n, Ans;
int a[2000300];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n;) {
    int j;
    for (j = i; a[j] == a[i] && j <= n; j++)
      ;
    j--;
    int cnt = j - i + 1, k;
    for (k = j + 1; a[k] != a[i] && k <= n; k++)
      ;
    k--;
    Ans = max(Ans, min(j - i + 1, k - j + 1));
    i = j + 1;
  }
  cout << Ans * 2 << endl;
  return 0;
}
