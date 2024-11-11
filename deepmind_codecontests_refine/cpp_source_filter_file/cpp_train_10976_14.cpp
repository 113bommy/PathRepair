#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
  vector<int> total;
  vector<int> team;
  int arr[2500], sum[2500];
  int n, k;
  cin >> n >> k;
  for (int(i) = 0; i < int(n); ++i) cin >> arr[i];
  for (int(i) = 0; i < int(n); ++i) {
    total.push_back(arr[i] + k);
  }
  for (int(i) = 0; i < int(total.size()); ++i) {
    if (total[i] <= k + 1) team.push_back(total[i]);
  }
  cout << team.size() / 3 << endl;
  return 0;
}
