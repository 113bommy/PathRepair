#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, now;
  cin >> n;
  vector<int> goodCars;
  bool good;
  for (int i = 0; i < n; i++) {
    good = true;
    for (int j = 0; j < n && good; j++) {
      cin >> now;
      if (now == 1 || now == 3) good = false;
    }
    if (good) goodCars.push_back(i + 1);
  }
  cout << goodCars.size() << endl;
  for (int i = 0; i < goodCars.size(); i++) {
    cout << goodCars[i] << " ";
  }
  return 0;
}
