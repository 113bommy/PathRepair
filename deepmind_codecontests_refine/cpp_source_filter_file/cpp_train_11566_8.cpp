#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  int x;
  int y = 0;
  int t = 0;
  cin >> x;
  int step[x];
  for (int i = 0; i < x; i++) {
    cin >> step[i];
  }
  for (int i = 0; i < x; i++) {
    if (step[i] > step[i + 1] || i == x - 1) {
      y++;
      a.push_back(step[i]);
    }
  }
  cout << y << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << a.at(i) << " ";
  }
  return 0;
}
