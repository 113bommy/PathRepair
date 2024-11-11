#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> Map;
bitset<200005> Ans;
bitset<200005> Text[4];
int Add[4][200005];
char T[200005], P[200005];
int main() {
  Map['A'] = 0;
  Map['C'] = 1;
  Map['G'] = 2;
  Map['T'] = 3;
  int t, p, k;
  char c;
  cin >> t >> p >> k;
  cin >> T >> P;
  for (int i = 0; i < t; i++) {
    c = Map[T[i]];
    Add[c][max(0, i - k)]++;
    Add[c][min(t, i + k + 1)]--;
    Ans[i] = 1;
  }
  for (int d = 0; d < 4; d++) {
    for (int i = 0; i < t; i++) {
      Add[d][i + 1] += Add[d][i];
      if (Add[d][i]) Text[d][i] = 1;
    }
  }
  for (int i = 0; i < p; i++) P[i] = Map[P[i]];
  for (int i = 0; i < p; i++) {
    Ans &= (Text[P[i]] << i);
  }
  cout << Ans.count();
  return 0;
}
