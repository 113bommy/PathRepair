#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  int times[101] = {0};
  cin >> n >> d;
  int jokes = -10;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> times[i];
    total = total + times[i];
    jokes += 10;
  }
  if (total + jokes <= d) {
    cout << (((d - total - jokes) + jokes) / 5);
  } else
    cout << -1;
  return 0;
}
