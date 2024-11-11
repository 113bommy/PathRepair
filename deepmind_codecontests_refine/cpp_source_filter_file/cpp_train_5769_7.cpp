#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
const long long oo = 1LL << 60;
const long long kNumMoves = 4;
const long long kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
struct Line {
  Line(long long slope, long long yOrd) : m(slope), c(yOrd) {}
  long long m;
  long long c;
};
class ConvexHullOptimization {
 public:
  ConvexHullOptimization() : cur(0) {}
  void Add(long long m, long long c) {
    while (!KeepCurrentTop(Line(m, c))) lines.pop_back();
    lines.push_back(Line(m, c));
  }
  long long GetValue(long long x) {
    if (cur >= lines.size()) cur = lines.size() - 1;
    while ((cur < lines.size() - 1) &&
           ((lines[cur].m * x + lines[cur].c) >=
            (lines[cur + 1].m * x + lines[cur + 1].c)))
      ++cur;
    return lines[cur].m * x + lines[cur].c;
  }

 private:
  bool KeepCurrentTop(const Line& l3) {
    int n = lines.size();
    if ((n - cur) < 2) return true;
    Line l2 = lines[n - 1];
    Line l1 = lines[n - 2];
    long long newCost = (l3.c - l1.c) * (l1.m - l2.m);
    long long oldCost = (l2.c - l1.c) * (l1.m - l3.m);
    return newCost > oldCost;
  }
  unsigned int cur;
  vector<Line> lines;
};
long long FindMinCost(vector<long long>& a, vector<long long>& b) {
  ConvexHullOptimization chullOpt;
  int n = a.size();
  chullOpt.Add(b[0], 0);
  long long cost = 0;
  for (int i = 1; i < int(n); ++i) {
    cost = chullOpt.GetValue(a[i]);
    if (i < n - 1) chullOpt.Add(b[i], cost);
  }
  return cost;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n);
  vector<long long> b(n);
  for (int i = 0; i < int(n); ++i) scanf("%I64d", &a[i]);
  for (int i = 0; i < int(n); ++i) scanf("%I64d", &b[i]);
  cout << FindMinCost(a, b);
  int i;
  cin >> i;
  return 0;
}
