#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y;
  cin >> n >> x >> y;
  vector<long long int> output(n, 1);
  y -= n;
  long long int sum = n;
  while (sum < x && y >= 0) {
    output[0]++;
    sum += output[0] * output[0] - (output[0] - 1) * (output[0] - 1);
    y--;
  }
  if (y < 0)
    cout << -1 << endl;
  else {
    for (int i = 0; i < n; i++) cout << output[i] << '\n';
  }
}
