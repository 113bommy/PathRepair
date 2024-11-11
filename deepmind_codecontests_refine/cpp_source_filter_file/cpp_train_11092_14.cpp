#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  long long arr[200000], x = 20000000001, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == 'L' && s[i - 1] == 'R') {
      if (x > ((arr[i] - arr[i - 1]) / 2)) x = (arr[i] - arr[i - 1]) / 2;
    }
  }
  if (x == 200001) {
    x = -1;
  }
  cout << x;
  return 0;
}
