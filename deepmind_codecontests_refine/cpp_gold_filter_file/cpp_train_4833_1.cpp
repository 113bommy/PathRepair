#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int solver[200001];
struct problem {
  int difficulty, index;
  bool operator<(problem t) const { return difficulty > t.difficulty; }
};
struct student {
  int ability, cost, index;
  bool operator<(const student &t) const { return ability > t.ability; }
};
vector<problem> problems;
vector<student> students;
bool possible(int x) {
  if (x == 0) return false;
  int k = 0;
  long long ss = s;
  priority_queue<int, vector<int>, greater<int> > cost;
  for (int i = 0; i < m; i += x) {
    int a = problems[i].difficulty;
    while (k < n && students[k].ability >= a) {
      cost.push(students[k].cost);
      k++;
    }
    if (cost.empty()) return false;
    ss -= cost.top();
    cost.pop();
  }
  if (ss >= 0) return true;
  return false;
}
void get(int x) {
  int k = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      cost;
  for (int i = 0; i < m; i += x) {
    int a = problems[i].difficulty;
    while (k < n && students[k].ability >= a) {
      cost.push(make_pair(students[k].cost, students[k].index));
      k++;
    }
    int b = cost.top().second;
    for (int j = i; j < min(m, i + x); j++) solver[problems[j].index] = b;
    cost.pop();
  }
}
int main() {
  cin >> n >> m >> s;
  problems.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> problems[i].difficulty;
    problems[i].index = i + 1;
  }
  students.resize(n);
  for (int i = 0; i < n; i++) cin >> students[i].ability;
  for (int i = 0; i < n; i++) cin >> students[i].cost;
  for (int i = 0; i < n; i++) students[i].index = i + 1;
  sort(problems.begin(), problems.end());
  sort(students.begin(), students.end());
  int small = 0, big = m, mid;
  while (small < big) {
    mid = (small + big) / 2;
    if (possible(mid))
      big = mid;
    else
      small = mid + 1;
  }
  if (!possible(small)) {
    cout << "NO\n";
    return 0;
  }
  get(small);
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    cout << solver[i];
    if (1 != m) cout << ' ';
  }
  cout << '\n';
}
