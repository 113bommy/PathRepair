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
int n;
int cnt[Sz];
int a[Sz];
int ans[Sz];
int main() {
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int best = 0;
    for (int j = i; j <= n; j++) {
      cnt[a[j]]++;
      if (cnt[a[j]] > cnt[best] || cnt[a[j]] == cnt[best] && best > a[j]) {
        best = a[j];
      }
      ans[best]++;
    }
    memset(cnt, 0, (n + 1) * 4);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
