#include <bits/stdc++.h>
using namespace std;
int dp[5][3][201][201];
pair<int, int> ans[5][3][201][201];
int dp_func(int total_sets, int sets_won_by_A, int A, int B) {
  if (sets_won_by_A == 3 || (total_sets - sets_won_by_A == 3)) {
    if (A == 0 && B == 0)
      return 0;
    else
      return -500;
  }
  if (dp[total_sets][sets_won_by_A][A][B] != 500)
    return dp[total_sets][sets_won_by_A][A][B];
  int anss = -500;
  pair<int, int> best_ans;
  int x;
  if (total_sets == 4)
    x = 15;
  else
    x = 25;
  int y;
  if (A >= x) {
    for (y = 0; y <= x - 3 && y <= B; y++) {
      if (anss < 1 + dp_func(total_sets + 1, sets_won_by_A + 1, A - x, B - y)) {
        anss = 1 + dp_func(total_sets + 1, sets_won_by_A + 1, A - x, B - y);
        best_ans = make_pair(x, y);
      }
    }
  }
  if (B >= x) {
    for (y = 0; y <= x - 3 && y <= A; y++)
      if (anss < (-1 + dp_func(total_sets + 1, sets_won_by_A, A - y, B - x))) {
        anss = (-1 + dp_func(total_sets + 1, sets_won_by_A, A - y, B - x));
        best_ans = make_pair(y, x);
      }
  }
  if (total_sets == 4) {
    x = 15;
    y = 13;
  } else {
    x = 25;
    y = 23;
  }
  while (A >= x && B >= y) {
    if (anss < 1 + dp_func(total_sets + 1, sets_won_by_A + 1, A - x, B - y)) {
      anss = 1 + dp_func(total_sets + 1, sets_won_by_A + 1, A - x, B - y);
      best_ans = make_pair(x, y);
    }
    ++x;
    ++y;
  }
  if (total_sets == 4) {
    x = 13;
    y = 15;
  } else {
    x = 23;
    y = 25;
  }
  while (A >= x && B >= y) {
    if (anss < (-1 + dp_func(total_sets + 1, sets_won_by_A, A - x, B - y))) {
      anss = -1 + dp_func(total_sets + 1, sets_won_by_A, A - x, B - y);
      best_ans = make_pair(x, y);
    }
    ++x;
    ++y;
  }
  dp[total_sets][sets_won_by_A][A][B] = anss;
  ans[total_sets][sets_won_by_A][A][B] =
      make_pair(best_ans.first, best_ans.second);
  return anss;
}
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 201; k++)
        for (int l = 0; l < 201; l++) dp[i][j][k][l] = 500;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (dp_func(0, 0, a, b) <= -5) {
      cout << "Impossible"
           << "\n";
      continue;
    } else {
      int x = a, y = b;
      int a_matches = 0;
      int cntr = 0;
      vector<pair<int, int> > v;
      while (x > 0 || y > 0) {
        int t1 = ans[cntr][a_matches][x][y].first;
        int t2 = ans[cntr][a_matches][x][y].second;
        pair<int, int> x1y1 = make_pair(t1, t2);
        v.push_back(x1y1);
        if (x1y1.first > x1y1.second) a_matches++;
        x -= x1y1.first;
        y -= x1y1.second;
        cntr++;
      }
      cout << a_matches << " " << cntr - a_matches << "\n";
      for (int i = 0; i < v.size(); i++)
        cout << v[i].first << ":" << v[i].second << " ";
      cout << "\n";
    }
  }
}
