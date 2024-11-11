#include <bits/stdc++.h>
using namespace std;
int N;
int X[200001];
vector<pair<int, int> > factors[200001];
bool DP[200001][50];
pair<int, int> parent[200001][50];
vector<pair<int, int> > ans;
vector<long long> squares;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N / 2; i++) {
    scanf("%d", &X[i]);
  }
  for (int i = 0; i < N / 2; i++) {
    for (int j = 1; j * j < X[i]; j++) {
      if (X[i] % j == 0) {
        int minus = j;
        int plus = X[i] / j;
        if (minus % 2 == plus % 2) {
          int a = (plus - minus) / 2;
          int b = (plus + minus) / 2;
          factors[i].push_back({a, b});
        }
      }
    }
  }
  for (int i = 0; i < N / 2; i++) {
    for (int j = 0; j < factors[i].size(); j++) {
      if (i == 0) {
        DP[i][j] = true;
        parent[i][j] = make_pair(-1, -1);
      } else {
        for (int k = 0; k < factors[i - 1].size(); k++) {
          if (DP[i - 1][k] && factors[i][j].first > factors[i - 1][k].second) {
            DP[i][j] = true;
            parent[i][j] = make_pair(i - 1, k);
            break;
          }
        }
      }
    }
  }
  int end = N / 2 - 1;
  int idx = -1;
  for (int j = 0; j < factors[end].size(); j++) {
    if (DP[end][j]) {
      idx = j;
      break;
    }
  }
  if (idx == -1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  pair<int, int> cur = make_pair(end, idx);
  while (cur.first != -1) {
    ans.push_back(cur);
    cur = parent[cur.first][cur.second];
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    squares.push_back((long long)factors[ans[i].first][ans[i].second].first);
    squares.push_back((long long)factors[ans[i].first][ans[i].second].second);
  }
  for (int i = 0; i < N; i++) {
    printf("%lld ", squares[i] * squares[i] -
                        (i == 0 ? 0 : squares[i - 1] * squares[i - 1]));
  }
}
