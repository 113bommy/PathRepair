#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int totalTigers = 0;
  for (char c : s) {
    if (c == 'T') totalTigers++;
  }
  s += s;
  int best = s.size();
  int currentTigers = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i - totalTigers >= 0 && s[i - totalTigers] == 'T') currentTigers--;
    if (s[i] == 'T') currentTigers++;
    if (i + 1 >= totalTigers) best = min(best, totalTigers - currentTigers);
  }
  cout << best << endl;
  return 0;
}
