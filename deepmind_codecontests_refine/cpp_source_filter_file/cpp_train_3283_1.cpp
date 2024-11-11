#include <bits/stdc++.h>
using namespace std;
string str;
map<string, int> ans1, ans2;
int ma1, ma2;
int main() {
  while (cin >> str) {
    int cnt = 0;
    while (true) {
      int i = str.find_last_of('\\');
      if (i == 2) break;
      str = str.substr(0, i);
      int tmp = ans1[str];
      ans1[str] += cnt;
      ans2[str]++;
      if (!tmp) cnt++;
      ma1 = max(ma1, ans1[str]);
      ma2 = max(ma2, ans2[str]);
    }
  }
  cout << ma1 << " " << ma2;
  return 0;
}
