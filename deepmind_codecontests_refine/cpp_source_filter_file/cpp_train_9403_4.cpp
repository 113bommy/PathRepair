#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int count = 0;
  int last_man_score;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int score;
    cin >> score;
    if (score > 0) {
      count++;
    }
    if (score <= 0) break;
    last_man_score = score;
  }
  if (last_man_score > 0) {
    for (int i = k; i < n; i++) {
      int score;
      cin >> score;
      if (score == last_man_score)
        count++;
      else
        break;
    }
  }
  cout << count << endl;
  return 0;
}
