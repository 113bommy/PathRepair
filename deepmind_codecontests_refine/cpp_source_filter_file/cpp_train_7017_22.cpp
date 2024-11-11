#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, arr[100000], i, j, temp[3];
  set<int> s;
  cin >> n >> d;
  for (i = 1; i <= n; i++) arr[i] = -1;
  for (i = 0; i < d; i++) {
    s.clear();
    for (j = 0; j < 3; j++) {
      cin >> temp[j];
      if (arr[temp[j]] != -1) {
        s.insert(arr[temp[j]]);
      }
    }
    for (j = 0; j < 3; j++) {
      if (arr[temp[j]] != -1) {
        continue;
      }
      if (s.find(0) == s.end()) {
        arr[temp[j]] = 0;
        s.insert(0);
      } else if (s.find(1) == s.end()) {
        arr[temp[j]] = 1;
        s.insert(1);
      } else if (s.find(2) == s.end()) {
        arr[temp[j]] = 2;
        s.insert(2);
      }
    }
  }
  for (i = 1; i <= n; i++) cout << arr[i] << " ";
}
