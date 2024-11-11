#include <bits/stdc++.h>
const int N = (int)1e5;
int arr[N];
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n, ans = 0;
  long long sum;
  std::map<std::pair<int, int>, bool> map;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  for (int i = 0; i < n - 2; i++) {
    sum = 0;
    for (int j = i + 1; j < n - 1; j++) {
      sum += arr[j];
      if (sum > 2 * arr[i]) break;
      if (arr[i] ^ arr[j + 1] == sum) ans++, map[{i, j + 1}] = 1;
    }
  }
  for (int i = n - 1; i > 1; i--) {
    sum = 0;
    for (int j = i - 1; j; j--) {
      sum += arr[j];
      if (sum > 2 * arr[i]) break;
      if (arr[i] ^ arr[j - 1] == sum) ans += !map[{j - 1, i}];
    }
  }
  std::cout << ans << '\n';
}
