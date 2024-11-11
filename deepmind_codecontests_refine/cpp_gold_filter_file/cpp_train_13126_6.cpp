#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum[2] = {0};
  cin >> n;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
      int in;
      cin >> in;
      sum[i] += in;
    }
  if (sum[0] >= sum[1])
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
