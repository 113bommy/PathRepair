#include <bits/stdc++.h>
using namespace std;
bool exist(string s1, string s2) {
  int j = 0;
  bool b;
  for (int i = 0; i < s2.size(); i++) {
    b = 0;
    for (; j < s1.size(); j++) {
      if (s2[i] == s1[j]) {
        b = 1;
        j++;
        break;
      }
    }
    if (!b) return 0;
  }
  return 1;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int start = 1, End = n, res;
  while (End >= start) {
    int mid = (start + End) / 2;
    string temp = s1;
    for (int i = 0; i < mid; i++) temp[arr[i] - 1] = '.';
    if (exist(temp, s2)) {
      res = mid;
      start = mid + 1;
    } else {
      End = mid - 1;
    }
  }
  cout << res;
  return 0;
}
