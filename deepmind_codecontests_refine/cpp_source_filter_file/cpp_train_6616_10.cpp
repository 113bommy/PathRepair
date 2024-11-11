#include <bits/stdc++.h>
using namespace std;
bool judge(string str1, string pair1) {
  string str = str1, pair = pair1;
  int lendi = str.size() - pair.size();
  if (lendi < 0) lendi = -lendi;
  string toadd = "";
  for (int i = 0; i < lendi; i++) {
    toadd += "0";
  }
  if (str.size() < pair.size()) {
    str = toadd + str;
  } else
    pair = toadd + pair;
  for (int j = 0; j < pair.size(); j++) {
    if (pair[j] - '0' != ((str[j] - '0') & 1)) return false;
  }
  return true;
}
int main() {
  priority_queue<int> que;
  int n;
  scanf("%d", &n);
  int tmp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    tmp -= i;
    que.push(tmp);
    if (que.top() > tmp) {
      ans += que.top() - tmp;
      que.pop();
      que.push(tmp);
    }
  }
  cout << ans << endl;
}
