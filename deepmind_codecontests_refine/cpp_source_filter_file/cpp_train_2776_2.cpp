#include <bits/stdc++.h>
long long get_single(std::vector<int> nums,
                     const std::vector<long long> &factorials) {
  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
  }
  if (sum == 0) {
    return 1;
  }
  long long ans = factorials[sum];
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      ans = ans / factorials[nums[i]];
    }
  }
  return ans;
}
long long get_single_full(std::vector<int> nums,
                          const std::vector<long long> &factorials) {
  long long ans = get_single(nums, factorials);
  if (nums[0] > 0) {
    std::vector<int> modified_nums(nums);
    modified_nums[0] -= 1;
    long long second = get_single(modified_nums, factorials);
    ans = ans - second;
  }
  return ans;
}
long long get_all(std::vector<int> nums,
                  const std::vector<long long> &factorials, int position) {
  long long total = 0;
  if (position >= 10) {
    return get_single_full(nums, factorials);
  }
  if (nums[position] > 1) {
    for (int now = 1; now < nums[position]; ++now) {
      std::vector<int> modified_nums(nums);
      modified_nums[position] = now;
      total += get_all(modified_nums, factorials, position + 1);
    }
  }
  total += get_all(nums, factorials, position + 1);
  return total;
}
int main() {
  long long n;
  std::cin >> n;
  std::vector<int> nums(10, 0);
  while (n > 0) {
    int now = n % 10;
    nums[now] += 1;
    n = n / 10;
  }
  std::vector<long long> factorials(19);
  factorials[0] = 1;
  for (int i = 1; i < 19; ++i) {
    factorials[i] = i * factorials[i - 1];
  }
  long long ans = get_all(nums, factorials, 0);
  std::cout << ans;
}
