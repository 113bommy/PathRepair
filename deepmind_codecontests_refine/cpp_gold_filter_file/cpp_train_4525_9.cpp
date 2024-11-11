#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[1000 * 2 + 200];
vector<int> m;
int main() {
  int n;
  int ans = 1, i = 0;
  cin >> n;
  for (int ii = 0; ii < n; ii++) {
    cin >> arr[ii].first;
    arr[ii].second = ii;
  }
  {
    int now = 1, index = i;
    sort(arr, arr + n);
    while (i < n) {
      now = 0;
      index = i;
      while (true) {
        if (arr[index].first == arr[index + 1].first && (index + 1) < n) {
          now++;
          m.push_back(index);
          index++;
        } else
          break;
      }
      i = index + 1;
      ans += now;
    }
    if (ans >= 3) {
      cout << "YES"
           << "\n";
      for (int j = 0; j < n; j++) cout << arr[j].second + 1 << " ";
      cout << "\n";
      swap(arr[m[0]].second, arr[m[0] + 1].second);
      for (int j = 0; j < n; j++) cout << arr[j].second + 1 << " ";
      cout << "\n";
      swap(arr[m[0]].second, arr[m[0] + 1].second);
      swap(arr[m[1]].second, arr[m[1] + 1].second);
      for (int j = 0; j < n; j++) cout << arr[j].second + 1 << " ";
      cout << "\n";
    } else
      cout << "NO";
  }
  return 0;
}
