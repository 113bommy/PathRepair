#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  string input;
  char pre;
  vector<char> stage;
  int n, k, ans = -1, cnt = 0;
  string::iterator iter;
  cin >> n >> k >> input;
  for (string::iterator iter = input.begin(); iter != input.end(); iter++)
    stage.push_back(*iter);
  vector<char>::iterator iter2 = stage.begin();
  sort(stage.begin(), stage.end());
  while (cnt < k && iter2 != stage.end()) {
    if (cnt == 0) {
      ans = *iter2 - 'a' + 1;
      pre = *iter2;
      cnt = 1;
    } else if (pre + 1 < *iter2) {
      ans += (*iter2 - 'a' + 1);
      pre = *iter2;
      cnt++;
    }
    iter2++;
  }
  if (cnt < k) ans = -1;
  cout << ans;
  return 0;
}
