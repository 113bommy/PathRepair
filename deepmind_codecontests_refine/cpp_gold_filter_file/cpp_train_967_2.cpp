#include <bits/stdc++.h>
using namespace std;
int changeBase(string &see, int base) {
  int ans{0};
  for (auto va : see) {
    ans *= base;
    int add = 0;
    if (va >= 'A')
      add += 10 + (va - 'A');
    else
      add += va - '0';
    if (add >= base) return 70;
    ans += add;
  }
  return ans;
}
int main() {
  string see;
  cin >> see;
  string part1 = "";
  int i = 0;
  while (see[i] != ':') {
    part1 += see[i++];
    if (part1.back() == '0' && part1.size() == 1) part1.pop_back();
  }
  ++i;
  string part2 = "";
  while (i < see.size()) {
    part2 += see[i++];
    if (part2.back() == '0' && part2.size() == 1) part2.pop_back();
  }
  vector<int> ans;
  for (int i = 1; i < 62; ++i) {
    int see1 = changeBase(part1, i);
    int see2 = changeBase(part2, i);
    if (see1 < 24 && see2 < 60) ans.push_back(i);
  }
  if (!ans.size())
    printf("0");
  else if (ans.back() == 61)
    printf("-1");
  else
    for (auto va : ans) printf("%d ", va);
  puts("");
  return 0;
}
