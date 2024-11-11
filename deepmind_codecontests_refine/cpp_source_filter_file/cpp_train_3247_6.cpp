#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
lb:
  while (q--) {
    long long n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    long long curr = 0;
    long long i = 0;
    while (i < n) {
      if (s[curr][i] == '1' || s[curr][i] == '2')
        i++;
      else {
        curr = 1 - curr;
        if (s[curr][i] == '1' || s[curr][i] == '2') {
          cout << "NO";
          goto lb;
        }
        i++;
      }
    }
    if (curr == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
