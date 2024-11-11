#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 5;
const long long INF = 1e15;
struct pt {
  long long x, y;
};
bool operator<(const pt& A, const pt& B) {
  if (A.x == B.x) return A.y > B.y;
  return A.x < B.x;
}
long long N;
long long DP[MAXN][2];
vector<long long> LEVEL;
map<long long, set<pt> > M;
long long dist(pt A, pt B) { return abs(A.x - B.x) + abs(A.y - B.y); };
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  long long x, y;
  for (int i = (0); i < (N); i++) {
    cin >> x >> y;
    M[max(x, y)].insert({x, y});
  }
  M[0].insert({0, 0});
  LEVEL.push_back(0);
  for (auto& K : M) LEVEL.push_back(K.first);
  for (int j = (0); j < (MAXN); j++)
    for (int i = (0); i < (2); i++) DP[j][i] = INF;
  for (int i = (0); i < (2); i++) DP[0][i] = 0;
  long long MAXL = LEVEL.size();
  for (int lvl = 1; lvl < MAXL; lvl++) {
    long long curr = LEVEL[lvl], prev = LEVEL[lvl - 1];
    auto ptcurr0 = *M[curr].begin(), ptcurr1 = *M[curr].rbegin();
    auto ptprev0 = *M[prev].begin(), ptprev1 = *M[prev].rbegin();
    DP[lvl][0] = min(DP[lvl][0], DP[lvl - 1][0] + dist(ptprev0, ptcurr1) +
                                     dist(ptcurr1, ptcurr0));
    DP[lvl][0] = min(DP[lvl][0], DP[lvl - 1][1] + dist(ptprev1, ptcurr1) +
                                     dist(ptcurr1, ptcurr0));
    DP[lvl][1] = min(DP[lvl][1], DP[lvl - 1][0] + dist(ptprev0, ptcurr0) +
                                     dist(ptcurr0, ptcurr1));
    DP[lvl][1] = min(DP[lvl][1], DP[lvl - 1][1] + dist(ptprev1, ptcurr0) +
                                     dist(ptcurr0, ptcurr1));
  }
  cout << min(DP[MAXL - 1][0], DP[MAXL - 1][1]) << endl;
  return 0;
}
