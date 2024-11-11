#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int poss = b.length() - a.length();
  int arr[200100] = {0};
  int sum = 0;
  for (int i = 0; i < b.size(); i++) {
    sum += b[i] - '0';
    arr[i + 1] = sum;
  }
  int ans = 0;
  for (int j = 0; j < a.length(); j++) {
    if (a[j] == '0')
      ans += (arr[j + poss + 1] - arr[j]);
    else
      ans += (poss + 1 - arr[j + poss + 1] + arr[j]);
  }
  cout << ans;
  return 0;
}
