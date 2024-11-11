#include <bits/stdc++.h>
using namespace std;
vector<int> Next[200005];
int have[200005];
int a = 0, b = 0;
void F(int here, int Fa, int deg) {
  for (auto i : Next[here]) {
    if (i == Fa) continue;
    F(i, here, deg + 1);
  }
  if (deg % 2)
    a++;
  else
    b++;
}
int main() {
  int N, i, a, b, small = 1e9;
  scanf("%d", &N);
  for (i = 1; i < N; i++) {
    scanf("%d %d", &a, &b);
    Next[a].push_back(b);
    Next[b].push_back(a);
  }
  F(1, 0, 0);
  printf("%d\n", min(a, b) - 1);
  return 0;
}
