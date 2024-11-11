#include <bits/stdc++.h>
using namespace std;
int arr[200200];
string in;
int n, m;
bool is_ok() {
  int dist = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i]) {
      dist = 0;
    } else {
      dist++;
    }
    if (dist >= m) {
      return false;
    }
  }
  return true;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> m >> in;
  n = in.length();
  string ans = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      if (in[j] - 'a' == i) {
        arr[j] = 1;
      }
    }
    if (!is_ok()) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (in[j] - 'a' == i) {
        arr[j] = 0;
      }
    }
    int dist = 0;
    int lst = -1;
    for (int j = 0; j < n; j++) {
      if (arr[j]) {
        dist = 0;
      } else {
        dist++;
      }
      if (in[j] - 'a' == i) {
        lst = j;
      }
      if (dist >= m) {
        arr[lst] = 1;
        dist = j - lst;
        lst = -1;
      }
    }
    break;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i]) {
      ans += in[i];
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;
}
