#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  long long s[a][a];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) cin >> s[i][j];
  }
  long long x = sqrt(s[0][1] * s[0][2] / s[1][0]);
  cout << x << " ";
  for (int i = 1; i < a; i++) cout << s[0][i] / x << " ";
}
