#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
vector<pair<int, int> > arr;
int w[N];
vector<int> z;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    arr.push_back({b + i, i});
  }
  sort(arr.begin(), arr.end());
  for (int k = 0; k < arr.size(); k++) {
    z.push_back(arr[k].first - k);
  }
  if (is_sorted(z.begin(), z.end())) {
    for (int k = 0; k < z.size(); k++) cout << z[k];
    return 0;
  }
  cout << ":(";
  return 0;
}
