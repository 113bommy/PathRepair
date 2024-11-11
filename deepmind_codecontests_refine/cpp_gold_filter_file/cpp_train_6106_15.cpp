#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int arr[maxn];
int findmin(int i) {
  int ans = 2e9 + 1000;
  for (int j = i - 4; j <= i; ++j) {
    ans = min(ans, arr[j]);
  }
  return ans;
}
int findmax(int i) {
  int ans = -2e9 - 1000;
  for (int j = i - 4; j <= i; ++j) {
    ans = max(ans, arr[j]);
  }
  return ans;
}
int main() {
  string str;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cin >> str;
  int temp;
  int r = 1e9;
  int l = -1e9;
  for (int i = 4; i < n; ++i) {
    if (str[i] == '1' && str[i - 1] == '0' && str[i - 2] == '0' &&
        str[i - 3] == '0' && str[i - 4] == '0') {
      temp = findmax(i);
      l = max(temp + 1, l);
    } else if (str[i] == '0' && str[i - 1] == '1' && str[i - 2] == '1' &&
               str[i - 3] == '1' && str[i - 4] == '1') {
      temp = findmin(i);
      r = min(temp - 1, r);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
