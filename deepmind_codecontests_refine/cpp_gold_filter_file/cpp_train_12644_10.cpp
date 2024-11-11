#include <bits/stdc++.h>
using namespace std;
const int Len = 100000;
string S[Len + 5][2];
string maxs;
int n;
int A[Len + 5];
void solve() {
  maxs = "a";
  for (int i = 1; i <= n; ++i) {
    if (S[A[i]][0].compare(maxs) >= 0)
      maxs = S[A[i]][0];
    else if (S[A[i]][1].compare(maxs) >= 0)
      maxs = S[A[i]][1];
    else {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) {
      string a, b;
      cin >> a >> b;
      if (a.compare(b) > 0) swap(a, b);
      S[i][0] = a;
      S[i][1] = b;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
    solve();
  }
  return 0;
}
