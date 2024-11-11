#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> scores;
  int ways = 0;
  int i;
  for (i = 0; i < n; i++) {
    int val;
    cin >> val;
    scores.push_back(val);
  }
  sort(scores.begin(), scores.end());
  for (i = 0; i < n; i++) {
    if (scores[i] > 0) {
      if (scores[i] > 0) {
        ways++;
      }
      if (scores[i] == scores[i + 1]) break;
    }
  }
  cout << ways;
  return 0;
}
