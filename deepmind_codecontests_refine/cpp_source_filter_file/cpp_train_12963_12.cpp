#include <bits/stdc++.h>
using namespace std;
pair<char, pair<int, int> > inp[5001];
int arr1[366], arr2[366];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp[i].first >> inp[i].second.first >> inp[i].second.second;
    if (inp[i].first == 'M') {
      for (int j = inp[i].second.first; j <= inp[i].second.second; j++) {
        arr1[j]++;
      }
    } else {
      for (int j = inp[i].second.first; j <= inp[i].second.second; j++) {
        arr2[j]++;
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < 366; i++) {
    mx = max(mx, min(arr1[i], arr2[i]) * 2);
  }
  cout << mx << endl;
  return 0;
}
