#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int m = 0;
  cin >> n >> m;
  int hero[n];
  int zero[m];
  vector<int> my;
  for (int i = 0; i < n; i++) {
    cin >> hero[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> zero[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (hero[i] == zero[j]) my.push_back(hero[i]);
    }
  }
  for (int i = 0; i < my.size(); i++) {
    cout << my[i] << " ";
  }
  return 0;
}
