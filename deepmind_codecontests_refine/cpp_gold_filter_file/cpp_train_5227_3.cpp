#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2010;
char s[maxn];
vector<pair<int, int> > ans;
void rev(int l, int r) {
  ans.push_back(make_pair(l + 1, r + 1));
  reverse(s + l, s + r + 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int cnt = n / 2 - k + 1;
    for (int i = 0; i < n; i++) {
      if (i < cnt || (i >= 2 * cnt && (i - 2 * cnt) % 2 == 0)) {
        int pos = -1;
        for (int j = i; j < n; j++) {
          if (s[j] == '(') {
            pos = j;
            break;
          }
        }
        rev(i, pos);
      } else {
        int pos = -1;
        for (int j = i; j < n; j++) {
          if (s[j] == ')') {
            pos = j;
            break;
          }
        }
        rev(i, pos);
      }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
}
