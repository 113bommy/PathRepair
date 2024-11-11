#include <bits/stdc++.h>
using namespace std;
void solve() {
  int totalHobbits, hobbitsNeeded = 3, durationOfParty = 3;
  cin >> totalHobbits;
  while (totalHobbits >= hobbitsNeeded + durationOfParty) {
    hobbitsNeeded += durationOfParty;
    durationOfParty++;
  }
  int hobbit = 1;
  vector<vector<int> > ans(durationOfParty);
  for (int i = 0; i < durationOfParty; i++) {
    for (int j = i + 1; j < durationOfParty; j++) {
      ans[i].push_back(hobbit);
      ans[j].push_back(hobbit);
      hobbit++;
    }
  }
  cout << durationOfParty << endl;
  for (int i = 0; i < durationOfParty; i++) {
    for (int j = 0; j < durationOfParty - 1; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  int t = 2;
  while (t--) {
    solve();
  }
  return 0;
}
