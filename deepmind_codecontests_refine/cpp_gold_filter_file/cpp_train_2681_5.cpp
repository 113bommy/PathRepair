#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int n, q;
struct data {
  int pos, val, isStart;
};
vector<data> V;
bool operator<(data a, data b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  return a.isStart > b.isStart;
}
int sltn[10000 + 10];
long double dp1[10000 + 10];
unsigned long long int dp2[10000 + 10];
int main() {
  scanf("%d %d", &n, &q);
  int st, ed, x;
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d", &st, &ed, &x);
    V.push_back({st, x, 1});
    V.push_back({ed, x, 0});
  }
  sort(V.begin(), V.end());
  dp1[0] = 1;
  dp2[0] = 1;
  for (auto v : V) {
    int x = v.val;
    if (v.isStart) {
      for (int i = n; i >= x; i--) {
        if (dp2[i - x] == 0 && dp1[i - x] < 1e5) continue;
        dp1[i] += (dp1[i - x]);
        dp2[i] += (dp2[i - x]);
        sltn[i] = 1;
      }
    } else {
      for (int i = x; i <= n; i++) {
        if (dp2[i - x] == 0 && dp1[i - x] < 1e5) continue;
        dp1[i] -= dp1[i - x];
        dp2[i] -= dp2[i - x];
      }
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (sltn[i]) res.push_back(i);
  }
  cout << res.size() << endl;
  for (auto v : res) printf("%d ", v);
  return 0;
}
