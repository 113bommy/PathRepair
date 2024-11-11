#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    v.push_back(c);
  }
  std::sort(v.begin(), v.end());
  int result = 0;
  if (k < v.size()) {
    if (k > 0 && v[k - 1] < v[k]) {
      result = v[k - 1];
    } else if (k == 0) {
      if (v[0] == 1) {
        result = -1;
      } else {
        result = v[0] - 1;
      }
    } else {
      result = -1;
    }
  } else {
    result = v.back();
  }
  std::cout << result << std::endl;
}
