#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    int sum = 1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 1) {
        count1++;
        if (count1 == 2) {
          sum = sum + 4;
        }
        sum++;
        count0 = 0;
      } else if (v[i] == 0) {
        count0++;
        if (count0 == 2) {
          sum = -1;
          break;
        }
        count1 = 0;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
