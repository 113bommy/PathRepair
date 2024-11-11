#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int num[102];
  num[0] = 0;
  num[1] = 0;
  num[2] = 1;
  for (int i = 3; i < 101; i++) num[i] += num[i - 1] + i - 1;
  cin >> n;
  int ans = 0;
  string s[101];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    int num1 = 0;
    int num2 = 0;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'C') num1++;
      if (s[j][i] == 'C') num2++;
    }
    ans += num[num1] + num[num2];
  }
  cout << ans << endl;
}
