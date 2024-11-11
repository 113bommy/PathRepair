#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int total = 0;
  vector<int> days;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int day;
    cin >> day;
    total += day;
    days.push_back(day);
  }
  int runningT = 0;
  int i;
  for (i = 0; i < days.size(); ++i) {
    runningT += days[i];
    if (runningT * 2 >= (total)) {
      ++i;
      break;
    }
  }
  cout << i << endl;
  return 0;
}
