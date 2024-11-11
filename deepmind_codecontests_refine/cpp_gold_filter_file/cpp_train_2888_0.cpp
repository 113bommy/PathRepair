#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  int sum[6] = {0, 0, 0, 0, 0, 0};
  char s[7];
  cin >> s;
  for (int i = 0; i < 7; i++) {
    if (s[i] == 'R') sum[1]++;
    if (s[i] == 'O') sum[2]++;
    if (s[i] == 'Y') sum[3]++;
    if (s[i] == 'G') sum[4]++;
    if (s[i] == 'B') sum[5]++;
    if (s[i] == 'V') sum[0]++;
  }
  sort(sum, sum + 6, cmp);
  int ans = 0;
  if (sum[0] == 6)
    ans = 1;
  else if (sum[0] == 5)
    ans = 1;
  else if (sum[0] == 4) {
    if (sum[1] == 2) ans = 2;
    if (sum[1] == 1) ans = 2;
  } else if (sum[0] == 3) {
    if (sum[1] == 3) ans = 2;
    if (sum[1] == 2) ans = 3;
    if (sum[1] == 1) ans = 5;
  } else if (sum[0] == 2) {
    if (sum[1] == 2) {
      if (sum[2] == 2) ans = 6;
      if (sum[2] == 1) ans = 8;
    }
    if (sum[1] == 1) ans = 15;
  } else if (sum[0] == 1)
    ans = 30;
  cout << ans << endl;
}
