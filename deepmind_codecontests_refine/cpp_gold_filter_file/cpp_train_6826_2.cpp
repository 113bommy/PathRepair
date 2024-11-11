#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s[n + 1];
  int mx = -100000;
  string name = "";
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int sum = 0;
    int arr[7];
    for (int j = 0; j < 7; ++j) {
      cin >> arr[j];
      if (j > 1) sum += arr[j];
    }
    sum += (arr[0] * 100);
    sum -= (arr[1] * 50);
    if (sum > mx) {
      mx = sum;
      name.clear();
      name += s[i];
    }
  }
  cout << name;
  return 0;
}
