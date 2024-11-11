#include <bits/stdc++.h>
using namespace std;
vector<int> parent, Rank, l;
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<pair<int, int>> bugs(m);
  vector<vector<int>> student(n, vector<int>(3));
  for (int i = 0; i < m; i++) {
    scanf("%d", &bugs[i].first);
    bugs[i].second = i;
  }
  sort(bugs.begin(), bugs.end());
  for (int i = 0; i < n; i++) scanf("%d", &student[i][0]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &student[i][1]);
    student[i][2] = i + 1;
  }
  sort(student.begin(), student.end());
  int lo = 1;
  int hi = m;
  bool valid = false;
  vector<int> memo;
  while (lo <= hi) {
    int time = lo + (hi - lo) / 2;
    vector<int> result(m);
    bool possible = true;
    int curr = m - 1;
    int other = n - 1;
    long long cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    while (curr >= 0) {
      while (other >= 0 and student[other][0] >= bugs[curr].first) {
        Q.emplace(student[other][1], student[other][2]);
        other--;
      }
      if (Q.empty()) break;
      pair<int, int> pick = Q.top();
      Q.pop();
      int t = time;
      cost += pick.first;
      while (t-- > 0 and curr >= 0) {
        result[bugs[curr].second] = pick.second;
        curr--;
      }
    }
    if (curr >= 0 or cost > s)
      lo = time + 1;
    else {
      valid = true;
      hi = time - 1;
      memo = move(result);
    }
  }
  if (valid == false) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < m; i++) {
    if (i != 0) printf(" ");
    printf("%d", memo[i]);
  }
  cout << endl;
}
