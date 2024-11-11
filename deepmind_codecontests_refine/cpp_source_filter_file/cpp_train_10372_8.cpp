#include <bits/stdc++.h>
using namespace std;
bool vis[123456];
int D[123456], Out[123456];
int main() {
  int n, cc = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &D[i + 1]);
  for (int i = 1; i <= n; i++) {
    int cnt = 0, p = D[i];
    while (!vis[p]) {
      vis[p] = true;
      cnt++;
      p = D[p];
    }
    if (cnt > 0) Out[cc++] = cnt;
  }
  sort(Out, Out + cc);
  long long O = 0;
  if (cc > 1) {
    long long o = Out[cc - 1] + (long long)Out[cc - 2];
    O += o * o;
    for (int i = 0; i < cc - 2; i++) {
      O += Out[i] * (long long)Out[i];
    }
    cout << O;
  } else
    cout << cc * (long long)cc;
}
