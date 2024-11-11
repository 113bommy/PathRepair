#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> poss;
int main() {
  cin >> t;
  int angles[t];
  for (int i = 0; i < t; i++) {
    cin >> angles[i];
  }
  for (int i = 3; i < 361; i++) {
    poss.push_back((180 * (i - 2)) / i);
  }
  for (int i = 0; i < t; i++) {
    if (find(poss.begin(), poss.end(), angles[i]) != poss.end()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
