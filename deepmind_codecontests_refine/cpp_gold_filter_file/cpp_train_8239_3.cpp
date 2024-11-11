#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > arr;
  int n;
  cin >> n;
  int sum = 0, other = 0;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    sum += in;
    arr.push_back({in, i});
  }
  other = sum - arr[0].first;
  sum = arr[0].first;
  vector<int> out;
  for (int i = 1; i < n; i++) {
    if (arr[0].first >= 2 * arr[i].first) {
      other -= arr[i].first;
      sum += arr[i].first;
      out.push_back(i + 1);
    }
    if (other < sum) {
      cout << out.size() + 1 << endl << 1 << " ";
      for (int i = 0; i < out.size(); i++) cout << out[i] << " ";
      return 0;
    }
  }
  cout << 0;
  return 0;
}
