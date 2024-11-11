#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, d;
  cin >> n >> d;
  vector<int> arr;
  arr.push_back(0);
  for (int i = 0; i < d; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }
  arr.push_back(n + 1);
  sort(arr.begin() + 1, arr.end() - 1);
  if (arr[1] == 1 || arr[n] == n) {
    cout << "NO\n";
    return 0;
  }
  vector<pair<int, int>> c;
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i + 1] - arr[i] - 1 > 0) {
      c.push_back({arr[i] + 1, arr[i + 1] - 1});
    }
  }
  for (int i = 0; i < c.size() - 1; i++) {
    if ((c[i + 1].first - c[i].second - 1) > 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
