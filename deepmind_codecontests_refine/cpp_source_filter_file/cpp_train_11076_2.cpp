#include <bits/stdc++.h>
using namespace std;
char str[1000010];
int h_sum;
char str_h[] = "heavy", str_m[] = "metal";
int judge_h(int x) {
  int k = 0;
  for (int i = x; i < x + 5; i++) {
    if (str[i] == str_h[i - x])
      k++;
    else
      break;
  }
  if (k == 5)
    return 1;
  else
    return 0;
}
int judge_m(int x) {
  int k = 0;
  for (int i = x; i <= x + 4; i++) {
    if (str[i] == str_m[i - x])
      k++;
    else
      break;
  }
  if (k == 5)
    return 1;
  else
    return 0;
}
int main() {
  cin >> str;
  int ans = 0;
  h_sum = 0;
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (str[i] == 'h') {
      if (judge_h(i)) {
        h_sum++;
      }
    } else if (str[i] == 'm') {
      if (judge_m(i)) {
        ans += h_sum;
      }
    }
  }
  cout << ans << endl;
}
