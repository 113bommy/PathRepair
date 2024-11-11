#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long nextLong() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
double nextDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
const int BUFSIZE = 1000000;
char buf[BUFSIZE + 1];
string nextString() {
  scanf("%s", buf);
  return buf;
}
string nextLine() {
  gets(buf);
  return buf;
}
int stringToInt(string s) {
  stringstream in(s);
  int x;
  in >> x;
  return x;
}
struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator-(Point op) const { return Point(x - op.x, y - op.y); }
  Point operator+(Point op) const { return Point(x + op.x, y + op.y); }
  Point operator*(double op) const { return Point(x * op, y * op); }
  double operator*(Point op) const { return x * op.x + y * op.y; }
  double operator%(Point op) const { return x * op.y - y * op.x; }
  double length2() { return x * x + y * y; }
  double lengt() { return sqrt(length2()); }
};
Point nextPoint() {
  double x = nextDouble();
  double y = nextDouble();
  return Point(x, y);
}
void update(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int lowerIndex(vector<int> &a, int x) {
  return lower_bound(a.begin(), a.end(), x) - a.begin();
}
int main() {
  int n = nextInt();
  vector<string> baseStrings(n);
  for (int i = 0; i < baseStrings.size(); ++i) {
    baseStrings[i] = nextString();
  }
  int m = nextInt();
  vector<int> b(m);
  for (int i = 0; i < b.size(); ++i) {
    b[i] = nextInt() - 1;
  }
  string s = nextString();
  const int INF = INT_MAX;
  vector<vector<vector<int> > > aIndexes(baseStrings.size(),
                                         vector<vector<int> >(26));
  for (int i = 0; i < baseStrings.size(); ++i) {
    for (int j = 0; j < baseStrings[i].size(); ++j) {
      int alpha = baseStrings[i][j] - 'a';
      aIndexes[i][alpha].push_back(j);
    }
  }
  vector<int> tPrefLength(b.size());
  for (int i = 1; i < tPrefLength.size(); ++i) {
    tPrefLength[i] = tPrefLength[i - 1] + baseStrings[b[i - 1]].size();
  }
  vector<vector<int> > lastAIndex(26, vector<int>(b.size(), -1));
  for (int alpha = 0; alpha < lastAIndex.size(); ++alpha) {
    for (int i = 0; i < lastAIndex[alpha].size(); ++i) {
      if (i > 0) {
        lastAIndex[alpha][i] = lastAIndex[alpha][i - 1];
      }
      if (!aIndexes[b[i]][alpha].empty()) {
        lastAIndex[alpha][i] = tPrefLength[i] + aIndexes[b[i]][alpha].back();
      }
    }
  }
  vector<vector<int> > dp(s.size() + 1, vector<int>(s.size() + 1, INF));
  dp[0][0] = -1;
  for (int i = 0; i + 1 < dp.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] < INF) {
        update(dp[i + 1][j], dp[i][j]);
        int alpha = s[i] - 'a';
        int pos = dp[i][j] + 1;
        int idx = lowerIndex(lastAIndex[alpha], pos);
        if (idx < b.size()) {
          int wordId = b[idx];
          int at = lowerIndex(aIndexes[wordId][alpha], pos - tPrefLength[idx]);
          int npos = tPrefLength[idx] + aIndexes[wordId][alpha][at];
          update(dp[i + 1][j + 1], npos);
        }
      }
    }
  }
  int res = 0;
  for (int len = 0; len <= s.size(); ++len) {
    if (dp[s.size()][len] < INF) {
      res = len;
    }
  }
  cout << res << endl;
  return 0;
}
