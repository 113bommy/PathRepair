#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  vector<bool> data;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    data.push_back(true);
  }
  for (int i = 0; i < m; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    data[temp1 - 1] = false;
    data[temp2 - 1] = false;
  }
  int best_i = 0;
  for (int i = 0; i < n; i++) {
    if (data[i]) {
      best_i = i;
      break;
    }
  }
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++) {
    if (i != best_i) {
      cout << i + 1 << " " << best_i + 1 << endl;
    }
  }
  return 0;
}
