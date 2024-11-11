#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
const int DX[6] = {+1, -1, 0, 0, 0, 0}, DY[6] = {0, 0, +1, -1, 0, 0},
          DZ[6] = {0, 0, 0, 0, +1, -1};
struct Laser {
  int x, y, z, dir, want;
  Laser() {}
  Laser(int x, int y, int z, int dir, int want)
      : x(x), y(y), z(z), dir(dir), want(want) {}
  void step() {
    x += DX[dir];
    y += DY[dir];
    z += DZ[dir];
  }
};
int na, nb, nc;
Laser laser[6 * MAXN];
int nlaser;
int ans[MAXN];
vector<int> who[MAXN];
queue<int> q;
bool solve() {
  for (int i = (0); i < (na * nb * nc); ++i) ans[i] = -1, who[i].clear();
  q = queue<int>();
  for (int i = (0); i < (nlaser); ++i) q.push(i);
  while (!q.empty()) {
    int at = q.front();
    q.pop();
    int x = laser[at].x, y = laser[at].y, z = laser[at].z,
        want = laser[at].want;
    if (x < 0 || x >= na || y < 0 || y >= nb || z < 0 || z >= nc) {
      if (want != 0) return false;
    } else {
      int target = x * nb * nc + y * nc + z;
      if (want == 0) {
        for (int i = (0); i < (((int)(who[target]).size())); ++i) {
          int to = who[target][i];
          laser[to].step();
          q.push(to);
        }
        who[target].clear();
        ans[target] = 0;
        laser[at].step();
        q.push(at);
      } else {
        if (ans[target] == -1) ans[target] = want;
        if (ans[target] != want) {
          for (int i = (0); i < (((int)(who[target]).size())); ++i) {
            int to = who[target][i];
            laser[to].step();
            q.push(to);
          }
          who[target].clear();
          ans[target] = 0;
          laser[at].step();
          q.push(at);
        } else {
          who[target].push_back(at);
        }
      }
    }
  }
  for (int i = (0); i < (na * nb * nc); ++i)
    if (ans[i] == -1) ans[i] = 0;
  return true;
}
void read(int x, int y, int z, int dir) {
  int want;
  scanf("%d", &want);
  laser[nlaser++] = Laser(x, y, z, dir, want);
}
void run() {
  scanf("%d%d%d", &na, &nb, &nc);
  nlaser = 0;
  for (int i = (0); i < (nb); ++i)
    for (int j = (0); j < (nc); ++j) read(0, i, j, 0);
  for (int i = (0); i < (nb); ++i)
    for (int j = (0); j < (nc); ++j) read(na - 1, i, j, 1);
  for (int i = (0); i < (na); ++i)
    for (int j = (0); j < (nc); ++j) read(i, 0, j, 2);
  for (int i = (0); i < (na); ++i)
    for (int j = (0); j < (nc); ++j) read(i, nb - 1, j, 3);
  for (int i = (0); i < (na); ++i)
    for (int j = (0); j < (nb); ++j) read(i, j, 0, 4);
  for (int i = (0); i < (na); ++i)
    for (int j = (0); j < (nb); ++j) read(i, j, nc - 1, 5);
  if (!solve()) {
    printf("-1\n");
    return;
  }
  for (int i = (0); i < (na); ++i) {
    if (i != 0) puts("");
    for (int j = (0); j < (nb); ++j) {
      for (int k = (0); k < (nc); ++k) {
        if (k != 0) printf(" ");
        printf("%d", ans[i * nb * nc + j * nc + k]);
      }
      puts("");
    }
  }
}
int main() {
  run();
  return 0;
}
