#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  long long arr[100000] = {0};
  long long counter = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.' && s[i + 1] == '.' || s[i] == '#' && s[i + 1] == '#') {
      counter++;
      arr[i] = counter;
    } else
      arr[i] = counter;
  }
  long long t;
  cin >> t;
  long long l, r;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    if (l == 1)
      counter = arr[r - 2];
    else
      counter = arr[r - 2] - arr[l - 2];
    cout << counter;
  }
  return 0;
}
