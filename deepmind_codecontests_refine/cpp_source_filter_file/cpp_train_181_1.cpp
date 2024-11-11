#include <iostream>
#include <limits>
using namespace std;

int main() {
  string s;
  cin >> s;
  int maxPrefix = 0, prefix[s.size() + 1];
  prefix[0] = 0;
  for (int i = 1; i <= s.size(); ++i) {
    if (s[i - 1] == '1') {
      prefix[i] = prefix[i - 1] + 1;
    } else {
      prefix[i] = prefix[i - 1] - 1;
    }
    maxPrefix = max(maxPrefix, prefix[i]);
  }
  auto solve = [&](int maxPrefix) {
    int capacity[s.size() + 1];
    for (auto i = s.size(), j = numeric_limits<int>::max(); i > 0; --i) {
      j = min(j, maxPrefix - prefix[i]);
      capacity[i] = j / 2;
    }
    int sum = 0, tempMaxPrefix = 0, tempMinPrefix = 0, count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        ++sum;
      } else if (s[i] == '0') {
        --sum;
      } else if (capacity[i + 1] > count) {
        ++sum;
        ++count;
      } else {
        --sum;
      }
      tempMaxPrefix = max(tempMaxPrefix, sum);
      tempMinPrefix = min(tempMinPrefix, sum);
    }
    return tempMaxPrefix - tempMinPrefix;
  };
  cout << min(solve(maxPrefix), solve(maxPrefix + 1));
  return 0;
}