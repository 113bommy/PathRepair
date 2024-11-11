#include <bits/stdc++.h>
using namespace std;
int64_t path_s[10000005] = {0}, path_e[10000005] = {0};
struct pair_hash {
  std::size_t operator()(pair<int64_t, int64_t> const& p) const {
    return (p.first + p.second) % int64_t(1e18);
  }
};
void findshortest(int64_t start, int64_t end) {
  int64_t temp_s = 0, temp_e = 0;
  path_s[temp_s++] = start;
  path_e[temp_e++] = end;
  while (start != end) {
    if (start > end) {
      start /= 2;
      path_s[temp_s++] = start;
    } else {
      end /= 2;
      path_e[temp_e++] = end;
    }
  }
  path_s[temp_s++] = -1;
  path_e[temp_e++] = -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t q, inp, start, end, inc;
  unordered_map<pair<int64_t, int64_t>, int64_t, pair_hash> weight;
  cin >> q;
  while (q--) {
    cin >> inp >> start >> end;
    if (inp == 1) {
      cin >> inc;
      findshortest(start, end);
      pair<int64_t, int64_t> p;
      for (int i = 0; path_s[i + 1] != -1; i++) {
        p = make_pair(path_s[i], path_s[i + 1]);
        if (weight.find(p) == weight.end())
          weight[p] = inc;
        else
          weight[p] += inc;
      }
      for (int i = 0; path_e[i + 1] != -1; i++) {
        p = make_pair(path_e[i], path_e[i + 1]);
        if (weight.find(p) == weight.end())
          weight[p] = inc;
        else
          weight[p] += inc;
      }
    } else {
      findshortest(start, end);
      int64_t ans = 0;
      pair<int64_t, int64_t> p;
      for (int i = 0; path_s[i + 1] != -1; i++) {
        p = make_pair(path_s[i], path_s[i + 1]);
        if (weight.find(p) != weight.end()) ans += weight[p];
      }
      for (int i = 0; path_e[i + 1] != -1; i++) {
        p = make_pair(path_e[i], path_e[i + 1]);
        if (weight.find(p) != weight.end()) ans += weight[p];
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
