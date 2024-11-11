#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp, size = 0, max = 0;
  cin >> n;
  vector<int> may(1000001);
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    cin >> may[temp];
    if (temp > size) size = temp;
  }
  vector<int> saved(size + 1);
  if (may[0] != 0) saved[0] = 1;
  for (int i = 1; i < size + 1; ++i) {
    if (may[i] == 0)
      saved[i] = saved[i - 1];
    else if (i > may[i])
      saved[i] = saved[i - may[i] - 1] + 1;
    else
      saved[i] = 1;
    if (saved[i] > max) max = saved[i];
  }
  cout << n - max;
}
