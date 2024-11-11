#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  if (scanf("%d%d", &a, &b) == 1) b = scanf("%*s");
  while (getchar() != '\n')
    ;
  long long num = 0;
  for (char c = getchar(); isalnum(c); c = getchar())
    num = num * a + c - (c >= 'A' ? 'A' - 10 : '0');
  if (!b) {
    vector<pair<int, string>> u = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};
    for (size_t i = 0; i < u.size(); i++) {
      while (num >= u[i].first) {
        num -= u[i].first;
        printf("%s", u[i].second.c_str());
      }
    }
  } else {
    vector<int> ans;
    do ans.push_back(num % b);
    while (num /= b);
    reverse(ans.begin(), ans.end());
    for (auto c : ans) putchar((c >= 10 ? 'A' - 10 : '0') + c);
  }
  puts("");
}
