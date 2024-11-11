#include <bits/stdc++.h>
using namespace std;
int main() {
  char yes[4] = "YES";
  char no[3] = "NO";
  int a_len;
  int b_len;
  cin >> a_len >> b_len;
  int k;
  int m;
  cin >> k >> m;
  int a_arr[a_len];
  int b_arr[b_len];
  for (int i = 0; i < a_len; i++) {
    cin >> a_arr[i];
  }
  for (int i = 0; i < b_len; i++) {
    cin >> b_arr[i];
  }
  for (int i = 0; i < m; i++) {
    if (a_arr[k - 1] >= b_arr[b_len - i]) {
      cout << no << endl;
      return 0;
    }
  }
  cout << yes << endl;
  return 0;
}
