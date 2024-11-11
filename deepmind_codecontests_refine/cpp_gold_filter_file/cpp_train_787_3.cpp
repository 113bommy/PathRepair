#include <bits/stdc++.h>
using namespace std;
char ans[3000050];
int main() {
  deque<char> que1, que2;
  string s1, s2;
  cin >> s1 >> s2;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  int n = s1.size(), stas = 0, ends = n - 1;
  for (int i = 0; i < (n + 1) / 2; i++) {
    que1.push_back(s1[i]);
  }
  for (int i = (n + 1) / 2; i < n; i++) {
    que2.push_back(s2[i]);
  }
  for (int i = 1, flag = 1; i <= n; i++) {
    if (flag) {
      if (que2.empty() || que1.front() >= que2.back()) {
        ans[ends--] = que1.back();
        que1.pop_back();
      } else {
        ans[stas++] = que1.front();
        que1.pop_front();
      }
    } else {
      if (que2.back() <= que1.front()) {
        ans[ends--] = que2.front();
        que2.pop_front();
      } else {
        ans[stas++] = que2.back();
        que2.pop_back();
      }
    }
    flag ^= 1;
  }
  ans[n] = '\0';
  printf("%s\n", ans);
  return 0;
}
