#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100], neg = 0;
  vector<int> v1, v2, v3;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < 0) neg++;
  }
  if (neg < 2) {
    for (int i = 0; i < n; i++) {
      if (arr[i] < 0)
        v1.push_back(arr[i]);
      else if (arr[i] > 0)
        v2.push_back(arr[i]);
      else
        v3.push_back(arr[i]);
    }
  } else if (neg > 2) {
    for (int i = 0; i < n; i++) {
      if (arr[i] < 0 && v1.size() == 0)
        v1.push_back(arr[i]);
      else if (arr[i] < 0 && v2.size() < 2)
        v2.push_back(arr[i]);
      else
        v3.push_back(arr[i]);
    }
  } else if (neg == 2) {
    for (int i = 0; i < n; i++) {
      if (arr[i] < 0 && v1.size() == 0)
        v1.push_back(arr[i]);
      else if (arr[i] > 0)
        v2.push_back(arr[i]);
      else
        v3.push_back(arr[i]);
    }
  }
  cout << v1.size() << " ";
  for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
  cout << endl;
  cout << v2.size() << " ";
  for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
  cout << endl;
  cout << v3.size() << " ";
  for (int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
  cout << endl;
  return 0;
}
