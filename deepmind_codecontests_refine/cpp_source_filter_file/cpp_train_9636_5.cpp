#include <bits/stdc++.h>
const int N = 2e5 + 5, lim = 100000;
int n;
long long r, t[N], l[N];
std::vector<int> ans;
int main() {
  std::cin >> n >> r;
  for (int i = 0; i < n; ++i) std::cin >> l[i];
  for (int i = 0; i < n; ++i) std::cin >> t[i];
  long long last = 0, sumt = 0, ans_s = 0;
  bool succ = true, output = true;
  for (int i = 0; i < n; ++i) {
    long long request = l[i] * 2 - t[i];
    if (request > l[i]) {
      succ = false;
      break;
    }
    if (last >= l[i]) {
      last -= l[i];
      sumt += l[i];
      continue;
    }
    sumt += last;
    l[i] -= last;
    t[i] -= last;
    request -= last;
    last = 0;
    if (request <= 0) {
      sumt += l[i] * 2;
      continue;
    }
    long long use = (request + r - 1) / r;
    long long all_time = use * r;
    long long tsumt = sumt + (l[i] - request) * 2;
    last = all_time - request;
    ans_s += use;
    if (use + ans.size() > lim) {
      output = false;
    } else {
      for (int j = 0; j < use; ++j) {
        ans.push_back(tsumt);
        tsumt += r;
      }
    }
    sumt += t[i];
  }
  if (!succ)
    std::cout << -1 << std::endl;
  else {
    std::cout << ans_s << std::endl;
    if (!output) return 0;
    for (int i = 0; i < (int)ans.size(); ++i)
      std::cout << ans[i] << (i == (int)ans.size() - 1 ? '\n' : ' ');
  }
}
