#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<char, int>> counts;
  map<char, int> map_counts;
  string input;
  int k;
  cin >> input >> k;
  for (const char& c : input) {
    if (map_counts.find(c) == map_counts.end()) {
      int c_count = count(input.begin(), input.end(), c);
      map_counts.insert(pair<char, int>(c, c_count));
    }
  }
  for (const auto& item : map_counts) {
    counts.emplace_back(item);
  }
  sort(counts.begin(), counts.end(),
       [](const pair<char, int>& a, const pair<char, int>& b) -> bool {
         return (a.second < b.second);
       });
  int lettersDel = 0;
  for (const auto& it : counts) {
    if (it.second <= k) {
      lettersDel++;
      k -= it.second;
    } else {
      break;
    }
  }
  int countsLength = counts.size();
  for (int i = 0; i < lettersDel; i++) {
    input.erase(remove(input.begin(), input.end(), counts[i].first),
                input.end());
    countsLength--;
  }
  cout << countsLength << "\n" << input;
  return 0;
}
