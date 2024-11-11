#include <bits/stdc++.h>
using namespace std;
long long n;
int qn;
void DFS(long long u) {
  if (u % 2) {
    printf("%lld\n", u / 2LL + 1);
    return;
  }
  DFS(u / 2 + n);
}
int main() {
  scanf("%lld%d", &n, &qn);
  int p;
  while (qn--) {
    scanf("%lld", &p);
    DFS(p);
  }
}
