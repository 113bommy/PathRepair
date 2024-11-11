#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> boxes(n, 0);
  vector<int> keys(m, 0);
  for (int i = 0; i < n; ++i) cin >> boxes[i];
  for (int i = 0; i < m; ++i) cin >> keys[i];
  int oddBoxes = count_if(boxes.begin(), boxes.end(),
                          [](int val) { return val % 2 == 1; });
  int evenBoxes = n - oddBoxes;
  int oddKeys =
      count_if(keys.begin(), keys.end(), [](int val) { return val % 2 == 1; });
  int evenKeys = m - oddKeys;
  int res = min(oddBoxes, evenKeys) + min(evenBoxes, oddKeys);
  cout << res << endl;
  return 0;
}
