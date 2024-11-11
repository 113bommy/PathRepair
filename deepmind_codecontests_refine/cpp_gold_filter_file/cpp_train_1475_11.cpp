#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    int sum = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
      int start = 0, end = arr.size() - 1, mid, ind, con;
      bool flag = false;
      while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] >= i + 1) {
          flag = true;
          end = mid - 1;
          ind = mid;
          con = arr[mid];
        } else
          start = mid + 1;
      }
      if (flag) {
        sum++;
        arr.erase(arr.begin() + ind);
      } else {
        break;
      }
    }
    cout << sum;
  }
  return 0;
}
