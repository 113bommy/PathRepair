#include <bits/stdc++.h>
using namespace std;
int l[7];
int main() {
  int n;
  cin >> n;
  string s;
  for (int x = 0; x < n; x++) {
    cin >> s;
    for (int i = 0; i < 7; i++) {
      l[i] += s[i] - '0';
    }
  }
  int mxn = 1;
  for (int x = 0; x < 7; x++) {
    mxn = max(mxn, l[x]);
  }
  cout << mxn << endl;
}
