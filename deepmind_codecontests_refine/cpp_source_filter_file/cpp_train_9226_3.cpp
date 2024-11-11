#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> tests;
  int maxV = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > maxV) maxV = x;
    tests.push_back(x);
  }
  vector<bool> chicken(maxV, false);
  chicken[0] = true;
  chicken[3] = true;
  chicken[6] = true;
  for (int i = 7; i < maxV; ++i) {
    if (!chicken[i - 3] && !chicken[i - 7]) continue;
    if (chicken[i - 3])
      chicken[i] = true;
    else if (chicken[i - 7])
      chicken[i] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (chicken[tests[i]])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
