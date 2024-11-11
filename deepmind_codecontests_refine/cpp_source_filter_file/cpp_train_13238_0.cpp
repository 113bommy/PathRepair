#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> ans;
  map<int, int> abhi_tak;
  for (int i = 0; i < n; i++) {
    int ss = arr[i];
    int cc = 0;
    for (auto x : abhi_tak) {
      int check = m - arr[i];
      int count = check / x.first;
      count = min(count, x.second);
      ss += (count * x.first);
      cc += count;
    }
    ans.push_back(i - cc);
    abhi_tak[arr[i]]++;
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
