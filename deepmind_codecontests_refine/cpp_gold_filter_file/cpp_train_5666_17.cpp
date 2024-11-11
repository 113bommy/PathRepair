#include <bits/stdc++.h>
using namespace std;
struct student_t {
  int id;
  int skills, cost;
  bool operator<(const student_t& o) const { return !(cost < o.cost); }
};
struct bug_t {
  int id, complexity, solver_id;
};
int N;
int M;
int S;
int C;
vector<bug_t> bugs;
vector<long long> tasks;
vector<student_t> student;
vector<vector<student_t> > solvers_list;
vector<pair<int, int> > used;
const int INF = 100000000;
inline long long ceil(const long long a, const long long b) {
  return a / b + !!(a % b);
}
bool by_bug_complexity(bug_t a, bug_t b) { return a.complexity < b.complexity; }
bool by_bug_id(bug_t a, bug_t b) { return a.id < b.id; }
bool by_skill(pair<int, int> a, pair<int, int> b) {
  return student[a.second].skills < student[b.second].skills;
}
bool works(int timeunits, bool build = false) {
  if (build) used.clear();
  priority_queue<student_t> Q;
  long long min_students = 0, suffsum = 0;
  long long total_cost = 0;
  for (int c = C - 1; c >= 0; --c) {
    min_students = ceil(tasks[c], timeunits) - suffsum;
    suffsum += min_students;
    for (int j = 0; j < (int)solvers_list[c].size(); ++j)
      Q.push(solvers_list[c][j]);
    if (Q.size() < min_students) return false;
    for (int j = 0; j < min_students; ++j) {
      total_cost += Q.top().cost;
      if (build)
        for (int t = 0; t < timeunits && M > (int)used.size(); ++t)
          used.push_back(pair<int, int>(0, Q.top().id));
      Q.pop();
    }
  }
  return total_cost <= S;
}
int solve(int lb, int ub) {
  int ans = INF;
  while (ub - lb > 0) {
    int it = (lb + ub) / 2;
    if (!works(it))
      lb = it + 1;
    else
      ans = ub = it;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &N, &M, &S);
  map<int, int> complexity;
  bugs.resize(M);
  for (int i = 0; i < M; i++) {
    int c;
    scanf("%d", &c);
    ++complexity[c];
    bugs[i].id = i;
    bugs[i].complexity = c;
  }
  for (auto it = complexity.begin(); it != complexity.end(); ++it) {
    tasks.push_back(it->second);
    it->second = C++;
  }
  student.resize(N);
  for (int i = 0; i < N; i++) student[i].id = i;
  for (int i = 0; i < N; i++) scanf("%d", &student[i].skills);
  for (int i = 0; i < N; i++) scanf("%d", &student[i].cost);
  solvers_list.resize(C);
  for (int i = 0; i < N; i++) {
    auto it = complexity.upper_bound(student[i].skills);
    if (it == complexity.begin()) continue;
    --it;
    solvers_list[it->second].push_back(student[i]);
  }
  for (int i = C - 2; i >= 0; --i) {
    tasks[i] += tasks[i + 1];
  }
  int ans = solve(1, 100001);
  if (ans == INF) {
    printf("NO\n");
  } else {
    printf("YES\n");
    works(ans, true);
    sort(used.begin(), used.end(), by_skill);
    for (int i = 0; i < M; i++) used[i].first = i;
    sort(bugs.begin(), bugs.end(), by_bug_complexity);
    for (int i = 0; i < M; i++) bugs[i].solver_id = used[i].second;
    sort(bugs.begin(), bugs.end(), by_bug_id);
    for (int i = 0; i < M; i++) printf("%d ", bugs[i].solver_id + 1);
    printf("\n");
  }
  return 0;
}
