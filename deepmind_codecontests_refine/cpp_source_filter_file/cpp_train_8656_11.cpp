#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, counter = 0;
    cin >> n;
    string s;
    cin >> s;
    int completion = 0;
    for (int i = n; i >= 0; i--) {
      counter++;
      if (s[i] == '8' && counter >= 11) {
        completion = 1;
        break;
      }
    }
    if (completion == 1) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
