#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  std::unordered_map<int, int> assigned_jobs;
  std::vector<int> jobs_choosen(n);
  for (auto &job : jobs_choosen) {
    std::cin >> job;
    ++assigned_jobs[job];
  }
  if (!(k -= assigned_jobs.size())) {
    std::cout << 0 << std::endl;
    return 0;
  }
  std::vector<std::pair<int, int>> persuading_time(n);
  for (int idler{0}; idler < n; ++idler) {
    std::cin >> persuading_time[idler].first;
    persuading_time[idler].second = idler;
  }
  std::sort(std::begin(persuading_time), std::end(persuading_time));
  long long answer{};
  for (const auto &time_idler : persuading_time) {
    int &idlers_count{assigned_jobs[jobs_choosen[time_idler.second]]};
    if (1 < idlers_count) {
      answer += time_idler.first;
      --k;
      --idlers_count;
    }
    if (!k) {
      break;
    }
  }
  std::cout << answer << std::endl;
}
