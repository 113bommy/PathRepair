#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp, w;
  double x;
  vector<int> v;
  cin >> n >> w;
  for (int i = 0; i < 2 * n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  if ((double)v[n] / (double)v[0] >= 2.0)
    x = v[0];
  else
    x = v[n] / 2.0;
  double sum = 3.0 * n * x;
  if (sum > w) sum = w;
  cout << setprecision(6) << sum;
  return 0;
}
