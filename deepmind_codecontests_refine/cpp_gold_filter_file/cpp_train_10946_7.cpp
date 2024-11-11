#include <bits/stdc++.h>
using namespace std;
string str = "abcacbaabcacba";
unsigned long long int a, b, c;
int answer(long long int aa, long long int bb, long long int cc) {
  int count, ans = -1;
  for (int j = 0; j < (int)str.size() / 2; j++) {
    count = 0;
    for (int i = j; i < (int)str.size(); i++) {
      if (str[i] == 'a') {
        aa--;
        count++;
      } else if (str[i] == 'b') {
        bb--;
        count++;
      } else if (str[i] == 'c') {
        cc--;
        count++;
      }
      if (aa < 0 || bb < 0 || cc < 0) {
        count--;
        break;
      }
    }
    cc = c;
    aa = a;
    bb = b;
    ans = max(ans, count);
  }
  return ans;
}
int main() {
  unsigned long long int mini;
  cin >> a >> b >> c;
  if (a > 3 && b > 2 && c > 2) {
    mini = min(a / 3, b / 2);
    mini = min(mini, c / 2);
    a -= 3 * mini;
    b -= 2 * mini;
    c -= 2 * mini;
    cout << mini * 7 + answer(a, b, c);
    return 0;
  } else {
    cout << answer(a, b, c);
    return 0;
  }
  return 0;
}
