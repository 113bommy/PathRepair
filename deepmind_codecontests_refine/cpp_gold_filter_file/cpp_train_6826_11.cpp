#include <bits/stdc++.h>
using namespace std;
int main() {
  int max = INT_MIN, i, k;
  int n, plus, minus, prob, score;
  cin >> n;
  string name;
  string leader;
  for (k = 0; k < n; k++) {
    cin >> name;
    cin >> plus >> minus;
    score = plus * 100 - minus * 50;
    for (i = 0; i < 5; i++) {
      cin >> prob;
      score += prob;
    }
    if (score > max) {
      leader = name;
      max = score;
    }
  }
  cout << leader << endl;
  return 0;
}
