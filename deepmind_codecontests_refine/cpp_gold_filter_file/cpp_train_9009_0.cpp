#include <bits/stdc++.h>
long long n, t;
long long tasks_time;
std::vector<long long> tasks;
int main() {
  std::cin >> n;
  tasks.reserve(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> t;
    tasks.push_back(t);
  }
  std::sort(tasks.begin(), tasks.end());
  for (int i = 0; i < n; ++i) tasks_time += tasks[i] * tasks[n - i - 1];
  std::cout << tasks_time % 10007;
  return 0;
}
