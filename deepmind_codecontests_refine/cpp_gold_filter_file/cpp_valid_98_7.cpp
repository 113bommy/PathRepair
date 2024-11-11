#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while (i < n - 1 && s[i] == s[i + 1]) i++;
    if (i == n - 1)
      cout << "-1 -1\n";
    else
      cout << i + 1 << " " << i + 2 << endl;
  }
}
