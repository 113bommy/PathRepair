#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
const int MAX_NR = 1e5;
int nr_used[MAX_NR + 1];
bitset<MAX_NR + 1> was_added;
int get_lowbit(const int &nr) { return nr & -nr; }
int get_nr_pos(const int &bound, const int &nr) {
  return (bound + nr) / (get_lowbit(nr) * 2);
}
int main() {
  cin.sync_with_stdio(0);
  int sum, limit;
  cin >> sum >> limit;
  vector<int> res_set;
  for (int i = 0; sum != 0; ++i, sum /= 2) {
    if ((1 << i) <= limit && sum % 2 == 1) {
      ++nr_used[1 << i];
      was_added[1 << i] = true;
      res_set.push_back(1 << i);
    } else if ((1 << i) > limit && sum == '1') {
      vector<pii> divided = {{(1 << i) / 2, 2}};
      while (true) {
        int aux = divided.back().second;
        int nr_cur_pos = get_nr_pos(limit, divided.back().first);
        if (nr_cur_pos - nr_used[divided.back().first] >
            divided.back().second) {
          nr_used[divided.back().first] += divided.back().second;
          divided.back().second = 0;
        } else {
          divided.back().second -= nr_cur_pos - nr_used[divided.back().first];
          nr_used[divided.back().first] = nr_cur_pos;
        }
        aux -= divided.back().second;
        for (int j = 0, cur_nr = divided.back().first; j < aux; ++j) {
          while (was_added[cur_nr] && cur_nr <= limit) {
            cur_nr += get_lowbit(cur_nr) * 2;
          }
          if (cur_nr > limit) {
            cout << "-1";
            return 0;
          }
          was_added[cur_nr] = true;
          res_set.emplace_back(cur_nr);
          cur_nr += get_lowbit(cur_nr) * 2;
        }
        if (divided.back().second == 0) {
          break;
        } else {
          pii cur_nr = divided.back();
          divided.pop_back();
          if (cur_nr.first / 2 == 0) {
            cout << "-1";
            return 0;
          }
          divided.push_back({cur_nr.first / 2, 2 * cur_nr.second});
        }
      }
    }
  }
  cout << res_set.size() << "\n";
  for (const int &nr : res_set) {
    cout << nr << " ";
  }
}
