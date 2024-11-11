#include <bits/stdc++.h>
using namespace std;
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long long MXLL = 4e18;
const int Sz = 1110111;
inline void Read_rap() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline void randomizer3000() {
  unsigned int seed;
  asm("rdtsc" : "=A"(seed));
  srand(seed);
}
void files(string problem) {
  if (fopen((problem + ".in").c_str(), "r")) {
    freopen((problem + ".in").c_str(), "r", stdin);
    freopen((problem + ".out").c_str(), "w", stdout);
  }
}
void localInput(const char in[] = "s") {
  if (fopen(in, "r")) {
    freopen(in, "r", stdin);
  } else
    cerr << "Warning: Input file not found" << endl;
}
int n, m, d;
int dp[1 << 20];
int a[Sz];
vector<int> b[Sz];
int main() {
  Read_rap();
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    while (k--) {
      int j;
      cin >> j;
      b[i].push_back(j);
      a[j] = i;
    }
    sort(b[i].begin(), b[i].end());
  }
  int ptr[Sz] = {0};
  for (int i = 1; i <= n; i++) {
    int mask = (1 << m) - 1;
    for (int j = 1; j <= m; j++) {
      while (ptr[j] + 1 < (int)(b[j].size()) && b[j][ptr[j]] < i) ptr[j]++;
      if (i <= b[j][ptr[j]] && b[j][ptr[j]] <= i + d - 1) mask ^= (1 << j - 1);
    }
    dp[mask] = 1;
  }
  int ans = m;
  for (int mask = (1 << m) - 1; mask >= 0; mask--) {
    for (int j = 0; j < m; j++) {
      dp[mask] |= dp[mask | (1 << j)];
    }
    if (!dp[mask]) ans = min(ans, __builtin_popcount(mask));
  }
  cout << ans;
  return 0;
}
