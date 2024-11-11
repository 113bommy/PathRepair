#include <bits/stdc++.h>
using namespace std;
long long int n, w;
vector<double> arr;
int main() {
  cin >> n >> w;
  arr.resize(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  cout << setprecision(8)
       << min((double)w * 1.00000, min(arr[0] * 3, arr[n] * 1.5)) << "\n";
  return 0;
}
