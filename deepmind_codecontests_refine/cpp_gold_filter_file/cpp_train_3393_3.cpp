#include <bits/stdc++.h>
using namespace std;
int16_t rotation_difference(string s1, string s2) {
  int16_t diff = 0;
  for (int16_t i = 0; i < s1.length(); i++) {
    if (s1 == s2) {
      return diff;
    }
    rotate(s2.begin(), s2.begin() + 1, s2.end());
    diff++;
  }
  return -1;
}
int main() {
  int16_t n;
  cin >> n;
  string strings[50];
  for (int16_t i = 0; i < n; i++) {
    cin >> strings[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  string s = strings[0];
  int16_t min_total_diffrence = INT16_MAX;
  for (int16_t i = 0; i < s.length(); i++) {
    rotate(s.begin(), s.begin() + 1, s.end());
    int16_t total = 0;
    for (int16_t j = 0; j < n; j++) {
      int16_t difference = rotation_difference(s, strings[j]);
      if (difference == -1) {
        cout << -1 << endl;
        return 0;
      }
      total += difference;
    }
    min_total_diffrence = min(min_total_diffrence, total);
  }
  cout << min_total_diffrence << endl;
}
