#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, char>, pair<int, int>>> ans;
int main() {
  int n, i, cnt;
  scanf("%d", &n);
  if (n < 4) printf("NO\n"), exit(0);
  cnt = 0;
  printf("YES\n");
  for (i = n; i > 7; i -= 4) {
    ans.push_back({{i, '+'}, {i - 3, i + i - 3}});
    ans.push_back({{i - 1, '+'}, {i - 2, i + i - 3}});
    ans.push_back({{i + i - 3, '-'}, {i + i - 3, 0}});
    cnt++;
  }
  if (i == 4) {
    ans.push_back({{4, '*'}, {3, 12}});
    ans.push_back({{12, '*'}, {2, 24}});
    ans.push_back({{24, '*'}, {1, 24}});
  } else if (i < 7) {
    if (i == 6) ans.push_back({{6, '-'}, {3, 3}});
    ans.push_back({{5, '-'}, {2, 3}});
    ans.push_back({{3, '-'}, {1, 2}});
    ans.push_back({{4, '*'}, {3, 12}});
    ans.push_back({{12, '*'}, {2, 24}});
  } else {
    ans.push_back({{6, '-'}, {5, 1}});
    ans.push_back({{7, '-'}, {1, 6}});
    ans.push_back({{6, '-'}, {3, 3}});
    ans.push_back({{4, '*'}, {3, 12}});
    ans.push_back({{12, '*'}, {2, 24}});
    ans.push_back({{24, '*'}, {1, 24}});
  }
  for (auto it : ans) {
    printf("%d %c %d = %d\n", it.first.first, it.first.second, it.second.first,
           it.second.second);
  }
  for (i = 0; i < cnt; i++) printf("24 + 0 = 24\n");
  return 0;
}
