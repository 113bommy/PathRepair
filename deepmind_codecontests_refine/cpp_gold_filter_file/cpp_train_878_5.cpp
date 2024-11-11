#include <bits/stdc++.h>
using namespace std;
int n;
struct parcel {
  int in, out, w, s, v, ind;
  parcel(int _ind, int _in, int _out, int _w, int _s, int _v) {
    in = _in;
    out = _out;
    w = _w;
    s = _s;
    v = _v;
    ind = _ind;
  }
};
bool funcOut(parcel &p1, parcel &p2) { return p1.out < p2.out; }
std::vector<parcel> col;
long long dp[501][1001];
long long solveOverlapping(vector<pair<int, int> > &set) {
  if (set.size() == 0) return 0;
  long long dp[2001] = {0};
  int j = 0;
  for (int i = 1; i < 2001; ++i) {
    if (col[set[j].first].out == i) {
      while (j < set.size() && col[set[j].first].out == i) {
        dp[i] = max(dp[i],
                    max(dp[i - 1],
                        dp[i - col[set[j].first].out + col[set[j].first].in] +
                            set[j].second + col[set[j].first].v));
        j++;
      }
      if (set.size() == j) {
        return dp[i];
      }
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[2000];
}
long long recur(int top, int rem) {
  if (dp[top][rem] != -1) return dp[top][rem];
  std::vector<pair<int, int> > inset;
  for (int i = 0; i < col.size(); ++i) {
    if (i != top && col[i].in >= col[top].in && col[i].out <= col[top].out) {
      int remS = std::min(rem - col[i].w, col[i].s);
      if (remS >= 0) {
        dp[i][remS] = recur(i, remS);
        inset.push_back(make_pair(i, dp[i][remS]));
      }
    }
  }
  if (inset.size() != 0)
    dp[top][rem] = solveOverlapping(inset);
  else
    dp[top][rem] = 0;
  return dp[top][rem];
}
int main() {
  memset(dp, -1, sizeof(dp));
  int s;
  cin >> n >> s;
  col.push_back(parcel(0, -1, 2000, 0, s, 0));
  for (int i = 0; i < n; i++) {
    int in, out, w, s, v;
    cin >> in >> out >> w >> s >> v;
    col.push_back(parcel(i + 1, in, out, w, s, v));
  }
  sort(col.begin(), col.end(), funcOut);
  cout << recur(int((col).size()) - 1, s) << endl;
}
