#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr1[n];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  int m;
  cin >> m;
  int arr2[m];
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }
  int ms = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((arr2[j]) % (arr1[i]) == 0) {
        ms = arr2[j] / arr1[i];
        v.push_back(ms);
      }
    }
  }
  int l = *max_element(v.begin(), v.end());
  int si = v.size();
  int count = 0;
  for (int i = 0; i < si; i++) {
    if (v[i] == l) {
      count++;
    }
  }
  cout << count;
}
