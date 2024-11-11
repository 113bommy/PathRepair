#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    double arr[n];
    int mx = -1;
    map<double, int> mp;
    double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      mp[(double)arr[i]]++;
      sum += arr[i];
    }
    vector<int> vec;
    for (int i = 0; i < n; i++) {
      double x = sum - arr[i];
      x = x / 2.0;
      if (mp[x] >= 1) {
        if (x == arr[i] && mp[arr[i]] >= 2)
          vec.push_back(i + 1);
        else if (x != arr[i] && mp[x] == 1)
          vec.push_back(i + 1);
      }
    }
    cout << vec.size() << endl;
    if (vec.size() >= 1) {
      for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
