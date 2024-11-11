#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, d = 0;
  cin >> n;
  char A, D;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      a++;
    } else {
      d++;
    }
  }
  if (a > d) cout << "Anton";
  if (a < d) cout << "Danik";
  if (a == d) cout << "Friendship";
}
