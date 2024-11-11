#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int N, M, numUD, numLR, numCorner, flag[4][maxn], ans[2][maxn], back[maxn << 1];
pair<int, int> conn[4][maxn];
bool ULexist;
vector<pair<pair<int, int>, pair<int, int> > > temp;
vector<vector<pair<pair<int, int>, pair<int, int> > > > cycle, cycle2;
inline pair<int, int> _conn(int x, int y) { return conn[x][y]; }
inline int dir(const pair<pair<int, int>, pair<int, int> > &a) {
  if (a.first.first == 0 && a.second.first == 1 ||
      a.first.first == 1 && a.second.first == 0)
    return 0;
  if (a.first.first == 1 && a.second.first == 2 ||
      a.first.first == 2 && a.second.first == 1)
    return 1;
  if (a.first.first == 2 && a.second.first == 3 ||
      a.first.first == 3 && a.second.first == 2)
    return 2;
  if (a.first.first == 3 && a.second.first == 0 ||
      a.first.first == 0 && a.second.first == 3)
    return 3;
  if (a.first.first == 0 && a.second.first == 2 ||
      a.first.first == 2 && a.second.first == 0)
    return 4;
  return 5;
}
pair<int, int> _virtual(int x, int y) {
  if (x == 0 && y <= numCorner) return pair<int, int>(3, y);
  if (x == 0 && y > M - numCorner) return pair<int, int>(1, M - y + 1);
  if (x == 1 && y <= numCorner) return pair<int, int>(0, M - y + 1);
  if (x == 1 && y > N - numCorner) return pair<int, int>(2, y + M - N);
  if (x == 2 && y <= numCorner) return pair<int, int>(3, N - y + 1);
  if (x == 2 && y > M - numCorner) return pair<int, int>(1, y + N - M);
  if (x == 3 && y <= numCorner) return pair<int, int>(0, y);
  if (x == 3 && y > N - numCorner) return pair<int, int>(2, N - y + 1);
  if (N < M)
    if (ULexist) {
      if (x == 0 && y <= M - numCorner - numUD) return pair<int, int>(3, y);
      if (x == 0 && y > M - numCorner - numUD)
        return pair<int, int>(2, y - (M - 2 * numCorner - numUD));
      if (x == 2 && y <= numCorner + numUD)
        return pair<int, int>(0, y + (M - 2 * numCorner - numUD));
      if (x == 2 && y > numCorner + numUD) return pair<int, int>(1, y + N - M);
      if (x == 1) return pair<int, int>(2, y + M - N);
      if (x == 3) return pair<int, int>(0, y);
    } else {
      if (x == 2 && y <= M - numCorner - numUD)
        return pair<int, int>(3, N - y + 1);
      if (x == 2 && y > M - numCorner - numUD)
        return pair<int, int>(0, y - (M - 2 * numCorner - numUD));
      if (x == 0 && y <= numCorner + numUD)
        return pair<int, int>(2, y + (M - 2 * numCorner - numUD));
      if (x == 0 && y > numCorner + numUD) return pair<int, int>(1, M - y + 1);
      if (x == 1) return pair<int, int>(0, M - y + 1);
      if (x == 3) return pair<int, int>(2, N - y + 1);
    }
  else if (ULexist) {
    if (x == 3 && y <= N - numCorner - numLR) return pair<int, int>(0, y);
    if (x == 3 && y > N - numCorner - numLR)
      return pair<int, int>(1, y - (N - 2 * numCorner - numLR));
    if (x == 1 && y <= numCorner + numLR)
      return pair<int, int>(3, y + (N - 2 * numCorner - numLR));
    if (x == 1 && y > numCorner + numLR) return pair<int, int>(2, y + M - N);
    if (x == 0) return pair<int, int>(3, y);
    if (x == 2) return pair<int, int>(1, y + N - M);
  } else {
    if (x == 1 && y <= N - numCorner - numLR)
      return pair<int, int>(0, M - y + 1);
    if (x == 1 && y > N - numCorner - numLR)
      return pair<int, int>(3, y - (N - 2 * numCorner - numLR));
    if (x == 3 && y <= numCorner + numLR)
      return pair<int, int>(1, y + (N - 2 * numCorner - numLR));
    if (x == 3 && y > numCorner + numLR) return pair<int, int>(2, N - y + 1);
    if (x == 0) return pair<int, int>(1, M - y + 1);
    if (x == 2) return pair<int, int>(3, N - y + 1);
  }
}
void Travel(pair<int, int> pos,
            vector<pair<pair<int, int>, pair<int, int> > > &cycle,
            pair<int, int> (*conn)(int, int)) {
  static int DFN(0);
  DFN++;
  while (flag[pos.first][pos.second] != DFN) {
    flag[pos.first][pos.second] = DFN;
    cycle.push_back(pair<pair<int, int>, pair<int, int> >(
        pos, conn(pos.first, pos.second)));
    pos = conn(pos.first, pos.second);
    flag[pos.first][pos.second] = DFN;
    pos.first = (pos.first + 2) % 4;
  }
}
void initKMP(vector<pair<pair<int, int>, pair<int, int> > > &s) {
  back[0] = -1;
  for (int i = 1, j = -1; i < s.size(); i++) {
    while (~j && s[j + 1] != s[i]) j = back[j];
    if (s[j + 1] == s[i]) j++;
    back[i] = j;
  }
}
template <class iter>
bool Check(iter s, int len, vector<pair<pair<int, int>, pair<int, int> > > &t) {
  if (t.size() != len) return false;
  int match(-1);
  for (int i = 0, j = -1; i < len * 2; i++) {
    while (~j && dir(t[j + 1]) != dir(s[i % len])) j = back[j];
    if (dir(t[j + 1]) == dir(s[i % len])) j++;
    if (j == t.size() - 1) {
      match = i;
      break;
    }
  }
  if (!~match) return false;
  for (int i = match - t.size() + 1, j = 0; j < t.size(); j++, i++) {
    ans[t[j].first.first & 1][t[j].first.second] =
        (t[j].first.first == s[i % len].first.first ? s[i % len].first.second
                                                    : s[i % len].second.second);
    ans[t[j].second.first & 1][t[j].second.second] =
        (t[j].second.first == s[i % len].first.first
             ? s[i % len].first.second
             : s[i % len].second.second);
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N + M; i++) {
    int x, y;
    char p, q;
    scanf(" %c %c%d%d", &p, &q, &x, &y);
    conn[((p) == 'T'   ? 0
          : (p) == 'R' ? 1
          : (p) == 'B' ? 2
                       : 3)][x] = pair<int, int>(((q) == 'T'   ? 0
                                                  : (q) == 'R' ? 1
                                                  : (q) == 'B' ? 2
                                                               : 3),
                                                 y);
    conn[((q) == 'T'   ? 0
          : (q) == 'R' ? 1
          : (q) == 'B' ? 2
                       : 3)][y] = pair<int, int>(((p) == 'T'   ? 0
                                                  : (p) == 'R' ? 1
                                                  : (p) == 'B' ? 2
                                                               : 3),
                                                 x);
    if (p == 'T' && q == 'B' || p == 'B' && q == 'T') numUD++;
    if (p == 'L' && q == 'R' || p == 'R' && q == 'L') numLR++;
  }
  if (numUD && numLR) return puts("No solution"), 0;
  for (int i = 0; i < 4; i++)
    for (int j = 1; j <= (i & 1 ? N : M); j++)
      if (!flag[i][j]) {
        cycle.push_back(vector<pair<pair<int, int>, pair<int, int> > >());
        Travel(pair<int, int>(i, j), cycle.back(), _conn);
      }
  for (int i = 0; i < cycle.size(); i++) {
    temp.clear();
    numCorner++;
    if (cycle[i].size() == 4)
      Travel(pair<int, int>(0, numCorner), temp, _virtual), initKMP(temp);
    if (!Check(cycle[i].begin(), cycle[i].size(), temp) &&
        !Check(cycle[i].rbegin(), cycle[i].size(), temp)) {
      numCorner--;
      for (int j = 0; !ULexist && j < cycle[i].size(); j++)
        ULexist |= (dir(cycle[i][j]) == 3);
      cycle2.push_back(cycle[i]);
    }
  }
  int pos(numCorner);
  for (int i = 0; i < cycle2.size(); i++) {
    temp.clear();
    Travel(pair<int, int>(N > M, ++pos), temp, _virtual);
    initKMP(temp);
    if (!Check(cycle2[i].begin(), cycle2[i].size(), temp) &&
        !Check(cycle2[i].rbegin(), cycle2[i].size(), temp))
      return puts("No solution"), 0;
  }
  for (int i = 1; i <= N; i++) {
    printf("%d", ans[1][i]);
    putchar(i < N ? ' ' : '\n');
  }
  for (int i = 1; i <= M; i++) {
    printf("%d", ans[0][i]);
    putchar(i < M ? ' ' : '\n');
  }
  return 0;
}
