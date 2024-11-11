#include <bits/stdc++.h>
using namespace std;
char str[100005];
int n, m;
bool check(char c) {
  int pre = -1;
  for (int i = 0; i < n; i++) {
    if (str[i] <= c) pre = i;
    if (i - pre >= m) return false;
  }
  return true;
}
int work(char c) {
  int res = 0;
  int pre = -1, bef = -1;
  for (int i = 0; i < n; i++) {
    if (str[i] < c)
      bef = i;
    else if (str[i] == c)
      pre = i;
    if (i - bef >= m) {
      res++;
      bef = pre;
    }
  }
  return res;
}
int main() {
  char res;
  string ans = "";
  scanf("%d %s", &m, str);
  n = strlen(str);
  for (int i = 'a'; i <= 'z'; i++)
    if (check(i)) {
      res = i;
      break;
    }
  for (int i = 0; i < n; i++)
    if (str[i] < res) ans += str[i];
  sort(ans.begin(), ans.end());
  int num = work(res);
  cout << ans;
  for (int i = 1; i <= num; i++) cout << res;
  cout << endl;
  return 0;
}
