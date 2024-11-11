#include <bits/stdc++.h>
using namespace std;
int n, k, ans_res = -2;
bool glas(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    int res = 0;
    vector<string> list;
    for (int j = 0; j < 4; j++) {
      string str;
      getline(cin, str);
      int h = str.length() - 1;
      int cnt = 0;
      while (1) {
        if (h < 0 || cnt == k) break;
        if (glas(str[h])) cnt++;
        h--;
      }
      if (cnt < k) {
        res = -1;
        break;
      }
      list.push_back(str.substr(h + 1, str.length() - h - 1));
    }
    if (res == -1) {
      puts("NO");
      return 0;
    }
    if (list[0] == list[1] && list[1] == list[2] && list[2] == list[3])
      res = 4;
    else if (list[0] == list[1] && list[2] == list[3])
      res = 1;
    else if (list[0] == list[2] && list[1] == list[3])
      res = 2;
    else if (list[0] == list[3] && list[1] == list[2])
      res = 3;
    else
      res = -1;
    if (ans_res == -2 || ans_res == res || ans_res == 4)
      ans_res = res;
    else if (res != 4)
      ans_res = -1;
  }
  if (ans_res == -1)
    puts("NO");
  else if (ans_res == 1)
    puts("aabb");
  else if (ans_res == 2)
    puts("abab");
  else if (ans_res == 3)
    puts("abba");
  else if (ans_res == 4)
    puts("aaaa");
  return 0;
}
