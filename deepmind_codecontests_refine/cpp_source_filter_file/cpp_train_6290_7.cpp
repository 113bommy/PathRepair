#include <bits/stdc++.h>
using namespace std;
char s[100010];
vector<pair<int, int> > nums;
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len;) {
    int st = i;
    i++;
    int ln = 1;
    while (s[i] == '0') i++, ln++;
    nums.push_back(make_pair(s[st], ln));
  }
  int cur = nums[0].first;
  len = nums[0].second;
  int sol = 0;
  int last = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (len < nums[i].second || (len == nums[i].second && cur < nums[i].first))
      last = i;
    len += nums[i].second;
  }
  printf("%d\n", nums.size() - last + 1);
  return 0;
}
