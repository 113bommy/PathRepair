#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int INF = (int)1e9 + 1;
const long double EPS = 1e-9;
void precalc() {}
const int maxn = 100 + 10;
char s[maxn];
int table[maxn][maxn];
int a[maxn];
int n;
bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < n; ++j) {
      table[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return 1;
}
void solve() {
  vector<int> ans;
  while (1) {
    bool ch = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        ch = 1;
        for (int j = 0; j < n; ++j) {
          a[j] -= table[i][j];
        }
        ans.push_back(i);
      }
    }
    if (!ch) {
      break;
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ((int)(ans).size()));
  for (int i = 0; i < ((int)(ans).size()); ++i) {
    printf("%d%c", ans[i] + 1, " \n"[i == ((int)(ans).size()) - 1]);
  }
}
int main() {
  srand(rdtsc());
  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
