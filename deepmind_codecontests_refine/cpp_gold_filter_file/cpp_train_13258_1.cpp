#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int kiritoStrength;
  tuple<int, int> dragonInfo;
  vector<tuple<int, int>> dragonArray;
  int dragonStrength;
  int dragonBonus;
  cin >> kiritoStrength >> n;
  for (int i = 0; i < n; i++) {
    cin >> dragonStrength >> dragonBonus;
    dragonInfo = make_tuple(dragonStrength, dragonBonus);
    dragonArray.push_back(dragonInfo);
  }
  sort(dragonArray.begin(), dragonArray.end());
  for (int i = 0; i < dragonArray.size(); i++) {
    if (kiritoStrength > get<0>(dragonArray[i])) {
      kiritoStrength += get<1>(dragonArray[i]);
    } else if (kiritoStrength <= get<0>(dragonArray[i])) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
  return 0;
}
