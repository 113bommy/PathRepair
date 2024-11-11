#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> worker_initial_job(n);
  std::vector<int> worker_cost(n);
  std::vector<int> job_to_assigned_worker_cost(k);
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      extra_worker_costs;
  for (int i = 0; i < n; i++) {
    std::cin >> worker_initial_job[i];
    --worker_initial_job[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> worker_cost[i];
  }
  for (int i = 0; i < n; i++) {
    int job_idx = worker_initial_job[i];
    int old_cost = job_to_assigned_worker_cost[job_idx];
    bool unassigned = old_cost == 0;
    if (unassigned) {
      job_to_assigned_worker_cost[job_idx] = worker_cost[i];
      continue;
    }
    if (old_cost > worker_cost[i]) {
      extra_worker_costs.push(worker_cost[i]);
    } else {
      extra_worker_costs.push(old_cost);
      job_to_assigned_worker_cost[job_idx] = worker_cost[i];
    }
  }
  int64_t sum = 0;
  for (int i = 0; i < k; i++) {
    if (!job_to_assigned_worker_cost[i]) {
      sum += extra_worker_costs.top();
      extra_worker_costs.pop();
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
