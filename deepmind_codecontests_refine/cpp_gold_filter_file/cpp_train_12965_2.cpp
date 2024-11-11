#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<bool> sieveFilter(102, true);
  vector<int> sievePrimary;
  vector<int> sieveSecondary;
  sieveFilter[0] = false;
  sieveFilter[1] = false;
  for (int i = 2; i < 50; ++i) {
    if (sieveFilter[i] == true) {
      if (i >= 11)
        sieveSecondary.push_back(i);
      else
        sievePrimary.push_back(i);
      int temp = i;
      for (int j = i; j < 102; j += temp) {
        sieveFilter[j] = false;
      }
    }
  }
  int found = 0;
  for (auto i : sievePrimary) {
    string answer;
    cout << i << "\n";
    fflush(stdout);
    cin >> answer;
    if (answer == "yes") {
      found++;
      cout << i * i << "\n";
      fflush(stdout);
      cin >> answer;
      if (answer == "yes") found++;
      if (found == 2) break;
    }
  }
  if (found >= 2) {
    cout << "composite";
  } else if (found == 1) {
    for (auto i : sieveSecondary) {
      string answer;
      cout << i << "\n";
      fflush(stdout);
      cin >> answer;
      if (answer == "yes") {
        found++;
        if (found == 2) break;
      }
    }
    if (found >= 2)
      cout << "composite";
    else
      cout << "prime";
  } else {
    cout << "prime";
  }
  return 0;
}
