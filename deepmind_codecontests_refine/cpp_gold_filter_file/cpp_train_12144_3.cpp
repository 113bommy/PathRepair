#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string s;
  cin >> s;
  const int n = s.size();
  vector<vector<int>> pos_by_letter(256);
  for (int i = 0; i < n; ++i) pos_by_letter[s[i]].push_back(i);
  auto get_pos = [&](const int shift, const int pos) {
    return s[(pos + shift + n) % n];
  };
  vector<vector<int>> shift_by_first_letter(256);
  for (int shift = 0; shift < n; ++shift) {
    int letter = s[shift];
    shift_by_first_letter[letter].push_back(shift);
    assert(letter = get_pos(shift, 0));
  }
  long double ans = 0;
  for (int let = 'a'; let <= 'z'; ++let) {
    if (shift_by_first_letter[let].empty()) continue;
    const long double cond = (long double)shift_by_first_letter[let].size() / n;
    const int possible_shifts = shift_by_first_letter[let].size();
    int best_unq = 0;
    for (int i = 0; i < n; ++i) {
      map<int, int> occur;
      for (int s : shift_by_first_letter[let]) {
        ++occur[get_pos(s, i)];
      }
      int unq = 0;
      for (auto& p : occur)
        if (p.second == 1) ++unq;
      best_unq = max(best_unq, unq);
    }
    ans += cond * best_unq / possible_shifts;
  }
  cout << fixed << setprecision(15) << ans << endl;
}
