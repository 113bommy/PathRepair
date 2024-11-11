#include <bits/stdc++.h>
using namespace std;
bool myComparison(pair<long long, long long> f, pair<long long, long long> g) {
  return f.second > g.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  vector<pair<long long, long long> > skills;
  long long cf, cm, n, MAX_skill, m;
  cin >> n >> MAX_skill >> cf >> cm >> m;
  for (long i = 0; i < n; i++) {
    pair<long long, long long> input_row;
    cin >> input_row.first;
    input_row.second = i;
    skills.push_back(input_row);
  }
  sort(skills.begin(), skills.end());
  long long cur_m = m, cur_min_level = 0;
  long long number_of_min_values;
  for (long i = 0; i < n; i++) {
    number_of_min_values = i;
    if (i * (skills[i].first - cur_min_level) > cur_m) {
      cur_min_level += (cur_m / i);
      cur_m -= (cur_m / i) * i;
      break;
    } else {
      cur_m -= i * (skills[i].first - cur_min_level);
      cur_min_level = skills[i].first;
    }
    if (i == n - 1) {
      cur_min_level += (cur_m / n);
      cur_m -= (cur_m / n) * n;
    }
  }
  if (cur_min_level >= MAX_skill) {
    cout << n * cf + MAX_skill * cm << endl;
    for (long i = 0; i < n; i++) {
      cout << MAX_skill << " ";
    }
    return 0;
  }
  long long best_value = cur_min_level * cm, best_number_of_max_values = 0,
            best_min_level = cur_min_level;
  for (long i = n - 1; i >= 0; i--) {
    cur_m -= (MAX_skill - max(skills[i].first, cur_min_level));
    while (cur_m < 0) {
      if (number_of_min_values >= i) {
        number_of_min_values = i - 1;
        if (number_of_min_values < 0) {
          break;
        }
      }
      if (skills[number_of_min_values].first < cur_min_level) {
        long long j = min(-cur_m / (number_of_min_values + 1),
                          cur_min_level - skills[number_of_min_values].first);
        cur_m += j * (number_of_min_values + 1);
        cur_min_level -= j;
        if (cur_m < 0 and skills[number_of_min_values].first < cur_min_level) {
          cur_m += number_of_min_values + 1;
          cur_min_level--;
        }
      } else {
        number_of_min_values--;
        if (number_of_min_values < 0) {
          break;
        }
      }
    }
    if (number_of_min_values < 0) {
      break;
    }
    if (best_value < cur_min_level * cm + (n - i) * cf) {
      best_value = cur_min_level * cm + (n - i) * cf;
      best_number_of_max_values = n - i;
      best_min_level = cur_min_level;
    }
  }
  for (long i = 0; i < best_number_of_max_values; i++) {
    skills[n - i - 1].first = MAX_skill;
  }
  sort(skills.begin(), skills.end(), myComparison);
  cout << best_value << endl;
  for (long i = 0; i < n; i++) {
    cout << max(skills[i].first, best_min_level) << " ";
  }
  return 0;
}
