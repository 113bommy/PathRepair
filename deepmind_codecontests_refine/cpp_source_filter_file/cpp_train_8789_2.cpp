#include <bits/stdc++.h>
using namespace std;
int pos[1001000], m, n;
long long calc(int station) {
  long long re = 0;
  int passenger = 0;
  for (int i = 0; i < station; i++) {
    if (passenger == 0) {
      re += abs((long long)pos[i] - pos[station]);
    }
    passenger++;
    if (passenger == m) passenger = 0;
  }
  passenger = 0;
  for (int i = n - 1; i > station; i--) {
    if (passenger == 0) {
      re += abs((long long)pos[i] - pos[station]);
    }
    passenger++;
    if (passenger == m) passenger = 0;
  }
  return re * (long long)2;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", pos + i);
  cout << calc((n + 1) / 2) << endl;
  return 0;
}
