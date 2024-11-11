#include <bits/stdc++.h>
long long int arr[1005] = {};
std::vector<int> ans;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  for (int i = n - 1; i > 0; i--) arr[i] -= arr[i - 1];
  for (int k = 1; k <= n; k++) {
    bool fail = false;
    for (int j = 0; j < k && !fail; j++) {
      bool all_same = true;
      for (int i = j + k; i < n && all_same; i += k) {
        if (arr[i] != arr[i - k]) {
          all_same = false;
        }
      }
      fail = (fail || !all_same);
    }
    if (!fail) ans.push_back(k);
  }
  std::cout << ans.size() << '\n';
  for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
    if (it != ans.begin()) std::cout << ' ';
    std::cout << *it;
  }
  std::cout << '\n';
}
