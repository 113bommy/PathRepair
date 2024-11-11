#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<int> Data[2];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      Data[0].push_back(a);
    else
      Data[1].push_back(a);
  }
  sort(Data[0].begin(), Data[0].end());
  sort(Data[1].begin(), Data[1].end());
  if (Data[0].size() == 0) {
    Data[1].pop_back();
  } else if (Data[1].size() == 0) {
    Data[0].pop_back();
  } else {
    int t = 0;
    if (Data[0].size() < Data[1].size()) {
      Data[1].pop_back();
      t = 0;
    } else {
      Data[0].pop_back();
      t = 1;
    }
    while (true) {
      if (t) {
        if (Data[1].empty()) break;
        Data[1].pop_back();
      } else {
        if (Data[1].empty()) break;
        Data[0].pop_back();
      }
      t = !t;
    }
  }
  int answer = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < Data[i].size(); j++) answer += Data[i][j];
  }
  cout << answer;
  return 0;
}
