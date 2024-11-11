#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int counter = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
      counter--;
    } else if (s[i] == '+') {
      counter++;
    }
    if (k < -counter) {
      k = -counter;
    }
  }
  cout << counter + k << endl;
  return 0;
}
