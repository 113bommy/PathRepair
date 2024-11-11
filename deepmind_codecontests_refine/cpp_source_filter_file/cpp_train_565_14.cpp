#include <bits/stdc++.h>
int N, h, sum, l, r, ans = int(1e9);
std::string s;
int main() {
  std::cin >> N >> s;
  h = std::count(s.begin(), s.end(), 'H');
  for (r = 0; r < h; ++r) sum += s[r] == 'T';
  for (l = 0; l < N; ++l) {
    ans = std::min(ans, sum);
    sum -= s[l] == 'T';
    sum += s[r] == 'T';
    r < N - 1 ? ++r : 0;
  }
  std::cout << std::min(ans, sum);
}
