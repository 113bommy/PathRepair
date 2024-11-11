#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int min[3] = {0};
  for (int i = 1; i <= 3; i++) {
    string s;
    cin >> s;
    if (s[1] == '<') {
      if (s[0] == 'A') min[0]++;
      if (s[0] == 'B') min[1]++;
      if (s[0] == 'C') min[2]++;
    }
    if (s[1] == '>') {
      if (s[2] == 'A') min[0]++;
      if (s[2] == 'B') min[1]++;
      if (s[2] == 'C') min[2]++;
    }
  }
  if (min[0] == min[1])
    cout << "Impossible";
  else {
    if (min[0] == 2) cout << "A";
    if (min[1] == 2) cout << "B";
    if (min[2] == 2) cout << "C";
    if (min[0] == 1) cout << "A";
    if (min[1] == 1) cout << "B";
    if (min[2] == 1) cout << "C";
    if (min[0] == 0) cout << "A";
    if (min[1] == 0) cout << "B";
    if (min[2] == 0) cout << "C";
  }
}
