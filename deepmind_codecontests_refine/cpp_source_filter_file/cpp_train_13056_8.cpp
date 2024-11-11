#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int NMAX = (int)1E3 + 7;
int n, maxLive, reg;
bool used[2000];
vector<int> us, timeUs;
int sumUs = 0;
int pw[2000], dmg[2000];
const int MAGIC = 100000;
int main() {
  cin >> n >> maxLive >> reg;
  for (int i = 0; i < int(n); ++i) cin >> pw[i] >> dmg[i];
  int cur = maxLive;
  for (int curTime = 0; curTime < int(MAGIC); ++curTime) {
    {
      cur -= sumUs;
      cur += reg;
      cur = min(cur, maxLive);
      if (cur <= 0) {
        puts("YES");
        printf("%d %d\n", curTime + 1, int((us).size()));
        for (int i = 0; i < int(int((us).size())); ++i)
          printf("%d %d\n", timeUs[i], us[i] + 1);
        exit(0);
      }
    }
    if (int((us).size()) < n) {
      int maxV = -1, maxIdx = -1;
      for (int i = 0; i < int(n); ++i) {
        if (used[i] || cur * 100 > pw[i] * maxLive) continue;
        if (maxIdx == -1 || maxV < dmg[i]) {
          maxV = dmg[i];
          maxIdx = i;
        }
      }
      if (maxIdx != -1) {
        sumUs += maxV;
        used[maxIdx] = true;
        us.push_back(maxIdx);
        timeUs.push_back(curTime);
      }
    }
  }
  puts("NO");
  return 0;
}
