#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j;
  cin >> n >> i >> j;
  string s;
  cin >> s;
  if (s[i - 1] == s[j - 1]) {
    cout << '0' << endl;
  } else {
    cout << '1' << endl;
  }
}
