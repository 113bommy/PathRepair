#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  const long long M = 1000000007ll;
  long n, k;
  std::cin >> n >> k;
  std::string s;
  std::getline(std::cin >> std::ws, s);
  std::vector<long> cnt(n + s.size() + 1);
  long end[26] = {};
  long pos[26] = {};
  cnt[0] = 1;
  for (long i = 0; i != (long)s.size(); ++i) {
    cnt[i + 1] = ((2ll * cnt[i]) % M + (M - end[s[i] - 'a'])) % M;
    end[s[i] - 'a'] = cnt[i];
    pos[s[i] - 'a'] = i + 1;
  }
  for (long i = (long)s.size(); i != n + (long)s.size(); ++i) {
    const int j = std::min_element(pos, pos + k) - pos;
    cnt[i + 1] = ((2ll * cnt[i]) % M + (M - end[j])) % M;
    end[j] = cnt[i];
    pos[j] = i + 1;
  }
  std::cout << cnt[s.size() + n] << "\n";
  return 0;
}
