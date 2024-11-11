#include <bits/stdc++.h>
using namespace std;
const int Infinity = 1000000000;
struct Info {
  int cost, type;
  Info() {
    cost = Infinity;
    type = -1;
  };
  Info(int ncost, int ntype) { cost = ncost, type = ntype; }
};
Info minInfo(Info a, Info b) { return (a.cost < b.cost) ? a : b; }
string first, second;
int n, m;
Info dp[1100][1100];
string toString(int number) {
  if (number == 0) return "0";
  string answer = "";
  while (number) {
    char digit = number % 10 + '0';
    answer = digit + answer;
    number /= 10;
  }
  return answer;
}
int main() {
  cin >> first >> second;
  n = first.size(), m = second.size();
  first += '#';
  second += '#';
  dp[n][m].cost = 0;
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      Info best;
      if (first[i] == second[j] && i < n && j < m) {
        Info current(dp[i + 1][j + 1].cost, 0);
        best = minInfo(best, current);
      }
      if (first[i] != second[j] && i < n && j < m) {
        Info current(dp[i + 1][j + 1].cost + 1, 1);
        best = minInfo(best, current);
      }
      if (i < n) {
        Info current(dp[i + 1][j].cost + 1, 2);
        best = minInfo(best, current);
      }
      if (j < m) {
        Info current(dp[i][j + 1].cost + 1, 3);
        best = minInfo(best, current);
      }
      dp[i][j] = minInfo(dp[i][j], best);
    }
  }
  cout << dp[0][0].cost << endl;
  int i = 0, j = 0;
  vector<string> answer;
  while (i != n || j != m) {
    if (dp[i][j].type == 0)
      i++, j++;
    else if (dp[i][j].type == 1) {
      int pos = i + 1;
      string action = "REPLACE " + toString(pos) + " " + second[j];
      answer.push_back(action);
      i++;
      j++;
    } else if (dp[i][j].type == 2) {
      int pos = i + 1;
      string action = "DELETE " + toString(pos);
      answer.push_back(action);
      i++;
    } else if (dp[i][j].type == 3) {
      int pos = i + 1;
      string action = "INSERT " + toString(pos) + " " + second[j];
      answer.push_back(action);
      j++;
    }
  }
  for (int i = answer.size() - 1; i >= 0; i--) {
    cout << answer[i] << endl;
  }
  return 0;
}
