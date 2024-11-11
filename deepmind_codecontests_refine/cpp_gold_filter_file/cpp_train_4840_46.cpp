#include <bits/stdc++.h>
using namespace std;
int main() {
  int ncars;
  cin >> ncars;
  vector<vector<int> > results(ncars);
  for (int i = 0; i < ncars; i++) {
    for (int j = 0; j < ncars; j++) {
      int input_data;
      cin >> input_data;
      results[i].push_back(input_data);
    }
  }
  int cnt = 0;
  queue<int> goodcars;
  for (int i = 0; i < ncars; i++) {
    int j = 0;
    while (((results[i][j] % 2 == 0) || (j == i)) && (j < ncars)) j++;
    if (j == ncars) {
      cnt++;
      goodcars.push(i);
    }
  }
  cout << cnt << endl;
  while (!goodcars.empty()) {
    cout << goodcars.front() + 1 << " ";
    goodcars.pop();
  }
  cout << endl;
}
