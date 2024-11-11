#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  string s;
  cin >> n >> m;
  int freqArr[m + 9];
  int counter = n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int i = 0; i <= m; i++) {
      freqArr[i] = 1;
    }
    for (int j = 0; j < s.length(); j++) {
      if (freqArr[s[j] - 48]) {
        freqArr[s[j] - 48] = 0;
      }
    }
    for (int x = 0; x <= m; x++) {
      if (freqArr[x]) {
        counter--;
        break;
      }
    }
  }
  cout << counter;
  return 0;
}
