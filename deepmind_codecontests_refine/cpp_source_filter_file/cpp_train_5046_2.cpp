#include <bits/stdc++.h>
using namespace std;
int f[66666];
int g[66666];
int que[66666];
int main() {
  int n;
  cin >> n;
  int head = 0, tail = 0;
  int edgeNum = 0;
  for (int i = 0; i < n; i++) {
    cin >> f[i] >> g[i];
    if (f[i] == 1) que[tail++] = i;
    edgeNum += f[i];
  }
  cout << edgeNum / 2 << endl;
  while (head < tail) {
    int now = que[head++];
    if (now == 0) continue;
    f[g[now]]--;
    g[g[now]] ^= now;
    if (f[g[now]] == 1) que[tail++] = g[now];
    cout << now << " " << g[now] << endl;
  }
  return 0;
}
