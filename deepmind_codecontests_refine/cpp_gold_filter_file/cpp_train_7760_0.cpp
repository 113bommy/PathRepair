#include <bits/stdc++.h>
using namespace std;
int t, num[150];
string temp;
int main() {
  cin >> t >> temp;
  int now = 0, res = 0x3f3f3f;
  for (int i = 0; i < t; i++) {
    num[temp[i]]++;
    int a = num[temp[i]];
    while (num[temp[now]] > 1) {
      num[temp[now]]--;
      now++;
    }
    if (a == 1)
      res = i - now + 1;
    else
      res = min(res, i - now + 1);
  }
  cout << res << endl;
}
