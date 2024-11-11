#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
int main() {
  if (false) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int r, n;
  while (cin >> r >> n) {
    if (n == 0) {
      if (r % 2) {
        cout << "WIN" << endl;
        continue;
      } else {
        cout << "LOSE" << endl;
        continue;
      }
    }
    vector<pair<int, int> > plan;
    for (int i = 0; i < n; i++) {
      int j, k;
      cin >> j >> k;
      j--;
      k--;
      plan.push_back(make_pair(j, k));
    }
    sort(plan.begin(), plan.end());
    bool hasFirst = plan[0].first > 1;
    bool hasLast = plan.back().first < r - 2;
    int count = 0;
    for (int i = 1; i < plan.size(); i++) {
      int test = plan[i].first - plan[i - 1].first - 1;
      if (plan[i].second != plan[i - 1].second) {
        test--;
      }
      count += test;
    }
    int c1 = 0;
    int c2 = 0;
    if (plan[0].first == 1) {
      count++;
    } else {
      c1 = plan[0].first;
    }
    if (plan.back().first == r - 2) {
      count++;
    } else {
      c2 += r - plan.back().first - 1;
    }
    if (hasFirst && hasLast) {
      bool isWin = c1 ^ c2;
      if (count % 2) {
        isWin = c1 ^ c2 ^ 1;
      }
      if (isWin) {
        cout << "WIN" << endl;
      } else {
        cout << "LOSE" << endl;
      }
    } else if (hasFirst || hasLast) {
      cout << "WIN" << endl;
    } else {
      if (count % 2) {
        cout << "WIN" << endl;
      } else {
        cout << "LOSE" << endl;
      }
    }
  }
  return 0;
}
