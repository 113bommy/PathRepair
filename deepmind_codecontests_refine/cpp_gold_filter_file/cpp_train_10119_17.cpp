#include <bits/stdc++.h>
using namespace std;
int toNum(const string s) {
  stringstream ss;
  ss << s;
  int num;
  ss >> num;
  return num;
}
int main() {
  int n, k;
  cin >> n >> k;
  string text;
  string arr[15] = {};
  string str[15] = {};
  int mini = 1 << 25;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int per[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int res = 1 << 30;
  int fact = 1;
  do {
    for (int i = 0; i < n; i++) str[i] = "";
    int maxi = 0;
    int mini = 1 << 30;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < k; j++) str[i] += arr[i][per[j]];
    for (int i = 0; i < n; i++) {
      int cur = toNum(str[i]);
      if (cur > maxi) maxi = cur;
      if (cur < mini) mini = cur;
    }
    if (maxi - mini < res) res = maxi - mini;
  } while (next_permutation(per, per + k));
  cout << res << endl;
  return 0;
}
