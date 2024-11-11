#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, t, length_attack = 0, length_defense = 0;
  cin >> n;
  cin >> m;
  string s;
  vector<int> Joe_attack, Joe_defense;
  for (i = 0; i < n; i++) {
    cin >> s;
    cin >> t;
    if (s == "ATK") {
      Joe_attack.push_back(t);
      length_attack++;
    } else {
      Joe_defense.push_back(t);
      length_defense++;
    }
    s = "";
  }
  sort(Joe_attack.begin(), Joe_attack.end());
  sort(Joe_defense.begin(), Joe_defense.end());
  vector<int> Fox;
  for (i = 0; i < m; i++) {
    cin >> t;
    Fox.push_back(t);
  }
  sort(Fox.rbegin(), Fox.rend());
  int ans1 = 0, ans2 = 0, j;
  i = 0;
  j = 0;
  while (i < m && j < length_attack && Fox[i] > Joe_attack[j]) {
    ans1 += Fox[i] - Joe_attack[j];
    i++;
    j++;
  }
  j = 0;
  for (i = m - 1; i >= 0; i--) {
    if (j == length_defense) break;
    if (Fox[i] > Joe_defense[j]) {
      j++;
      Fox[i] = 0;
    }
  }
  if (j == length_defense) {
    sort(Fox.begin(), Fox.end());
    j = 0;
    for (i = 0; i < m; i++) {
      if (j == length_attack) break;
      if (Fox[i] > Joe_attack[j]) j++;
    }
    if (j == length_attack) {
      t = 0;
      ans2 = accumulate(Fox.begin(), Fox.end(), ans2) -
             accumulate(Joe_attack.begin(), Joe_attack.end(), t);
    }
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
