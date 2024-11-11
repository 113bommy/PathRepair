#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:26777216")
using namespace std;
const long long MOD = 100000007;
const long long LINF = 1000000097999999903LL;
long long boundz = 10000000001;
const int INF = (1 << 29);
int mem[1050][1050];
int arr[1050 + 1050];
int need[1050];
int nodeHit[1050 + 1050];
int N, cntz, maxHit, totRet;
void reset() {
  memset(nodeHit, 0, sizeof(nodeHit));
  memset(mem, 0, sizeof(mem));
  totRet = cntz = maxHit = 0;
}
int f(int qi, int qj, int got) {
  if (qi == qj) {
    return mem[qi][qj] - got;
  }
  int mid = (qi + qj) / 2;
  return mem[qi][qj] - got + f(qi, mid, mem[qi][qj]) +
         f(mid + 1, qj, mem[qi][qj]);
}
int f1(int i, int dist, int got) {
  if (dist == N) return got;
  int leftz = f1(2 * i, dist + 1, got + arr[2 * i]);
  int rightz = f1(2 * i + 1, dist + 1, got + arr[2 * i + 1]);
  int r1 = leftz, r2 = rightz;
  if (r1 > r2) swap(r1, r2);
  totRet += r2 - r1;
  return r1;
}
int main() {
  reset();
  scanf("%d", &N);
  int maxHit = 0;
  nodeHit[1] = 0;
  for (int i = (2); i <= ((1 << (N + 1)) - 1); i++) {
    scanf("%d", &arr[i]);
    nodeHit[i] = nodeHit[i / 2] + arr[i];
    maxHit = max(maxHit, nodeHit[i]);
  }
  f1(1, 0, 0);
  printf("%d\n", totRet);
  return 0;
  for (int i = (1 << N); i <= ((1 << (N + 1)) - 1); i++) {
    need[i - (1 << N) + 1] = maxHit - nodeHit[i];
  }
  for (int i = (1); i <= (1 << N); i++) {
    mem[i][i] = need[i];
    for (int j = (i + 1); j <= (1 << N); j++) {
      mem[i][j] = min(need[j], mem[i][j - 1]);
    }
  }
  int mid = (1 + (1 << N)) / 2;
  int leftz = f(1, mid, 0);
  int rightz = f(mid + 1, 1 << N, 0);
  int ret = leftz + rightz;
  printf("%d\n", ret);
  return 0;
}
