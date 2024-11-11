#include <bits/stdc++.h>
using namespace std;
inline int dist(const pair<int, int>& a, const pair<int, int>& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
void bfs(int n, int m, const vector<vector<int> >& a,
         const vector<pair<int, int> >& pPairs,
         const vector<vector<long long> >& dp,
         vector<vector<long long> >& dists) {
  priority_queue<pair<long long, pair<int, int> > > source;
  for (int i = 0; i < pPairs.size(); ++i) {
    source.push(make_pair(-dp[pPairs[i].first][pPairs[i].second],
                          make_pair(pPairs[i].first, pPairs[i].second)));
  }
  queue<pair<int, int> > q;
  const pair<int, int>& firstPos = source.top().second;
  dists[firstPos.first][firstPos.second] = -source.top().first;
  q.push(make_pair(firstPos.first, firstPos.second));
  source.pop();
  while (!q.empty()) {
    const pair<int, int>& t = q.front();
    while (!source.empty()) {
      const pair<long long, pair<int, int> >& s = source.top();
      if (s.first > dists[t.first][t.second]) {
        break;
      }
      dists[s.second.first][s.second.second] = -s.first;
      q.push(make_pair(s.second.first, s.second.second));
      source.pop();
    }
    if (t.first > 0) {
      pair<int, int> toAdd = make_pair(t.first - 1, t.second);
      if (dists[toAdd.first][toAdd.second] == LLONG_MAX) {
        dists[toAdd.first][toAdd.second] =
            min(dists[toAdd.first][toAdd.second], dists[t.first][t.second] + 1);
        q.push(make_pair(toAdd.first, toAdd.second));
      }
    }
    if (t.first < n - 1) {
      pair<int, int> toAdd = make_pair(t.first + 1, t.second);
      if (dists[toAdd.first][toAdd.second] == LLONG_MAX) {
        dists[toAdd.first][toAdd.second] =
            min(dists[toAdd.first][toAdd.second], dists[t.first][t.second] + 1);
        q.push(make_pair(toAdd.first, toAdd.second));
      }
    }
    if (t.second > 0) {
      pair<int, int> toAdd = make_pair(t.first, t.second - 1);
      if (dists[toAdd.first][toAdd.second] == LLONG_MAX) {
        dists[toAdd.first][toAdd.second] =
            min(dists[toAdd.first][toAdd.second], dists[t.first][t.second] + 1);
        q.push(make_pair(toAdd.first, toAdd.second));
      }
    }
    if (t.second < m - 1) {
      pair<int, int> toAdd = make_pair(t.first, t.second + 1);
      if (dists[toAdd.first][toAdd.second] == LLONG_MAX) {
        dists[toAdd.first][toAdd.second] =
            min(dists[toAdd.first][toAdd.second], dists[t.first][t.second] + 1);
        q.push(make_pair(toAdd.first, toAdd.second));
      }
    }
    q.pop();
  }
}
long long Solve(int n, int m, int p, const vector<vector<int> >& a,
                const vector<vector<pair<int, int> > >& pToInd) {
  vector<vector<long long> > dp(n, vector<long long>(m, LLONG_MAX));
  dp[pToInd[p][0].first][pToInd[p][0].second] = 0;
  for (int curP = p - 1; curP >= 1; --curP) {
    const vector<pair<int, int> >& curPPairs = pToInd[curP];
    const vector<pair<int, int> >& curPPlusPairs = pToInd[curP + 1];
    if (curPPairs.size() * curPPlusPairs.size() < m * n) {
      for (int i = 0; i < curPPairs.size(); ++i) {
        const pair<int, int>& curPair = curPPairs[i];
        for (int j = 0; j < curPPlusPairs.size(); ++j) {
          const pair<int, int>& toPair = curPPlusPairs[j];
          long long thisDist =
              dp[toPair.first][toPair.second] + dist(curPair, toPair);
          if (dp[curPair.first][curPair.second] > thisDist) {
            dp[curPair.first][curPair.second] = thisDist;
          }
        }
      }
    } else {
      vector<vector<long long> > dists(n, vector<long long>(m, LLONG_MAX));
      bfs(n, m, a, curPPlusPairs, dp, dists);
      for (int i = 0; i < curPPairs.size(); ++i) {
        const pair<int, int>& curPair = curPPairs[i];
        dp[curPair.first][curPair.second] =
            dists[curPair.first][curPair.second];
      }
    }
  }
  if (a[0][0] == 1) {
    return dp[0][0];
  } else {
    const vector<pair<int, int> >& curPPlusPairs = pToInd[1];
    pair<int, int> curPair = make_pair(0, 0);
    long long result = LLONG_MAX;
    for (int j = 0; j < curPPlusPairs.size(); ++j) {
      long long thisDist = dp[curPPlusPairs[j].first][curPPlusPairs[j].second] +
                           dist(curPair, curPPlusPairs[j]);
      if (result > thisDist) {
        result = thisDist;
      }
    }
    return result;
  }
}
int main() {
  iostream::sync_with_stdio(false);
  int n = 0;
  int m = 0;
  int p = 0;
  cin >> n >> m >> p;
  vector<vector<int> > a(n, vector<int>(m, 0));
  vector<vector<pair<int, int> > > pToInd(p + 1, vector<pair<int, int> >());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      pToInd[a[i][j]].push_back(make_pair(i, j));
    }
  }
  cout << Solve(n, m, p, a, pToInd);
  return 0;
}
