#include <bits/stdc++.h>
using namespace std;
const int MAX = 5002;
char c[MAX], a[MAX];
bool check(int b1, int d1, int a, int b, int c, int d) {
  int n = a + b + c + d;
  int a1 = (n >> 1) - b - d + d1;
  int c1 = b + d - b1 - (d1 << 1);
  return a1 >= 0 && a1 <= a && c1 >= 0 && c1 <= c;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    scanf(" %s %s", c, a);
    vector<int> art[4];
    for (int i = 0; i < n; i++) {
      art[((c[i] - '0') << 1) | (a[i] - '0')].push_back(i);
    }
    vector<int> ans;
    bool found = false;
    for (size_t b = 0; b <= art[1].size(); b++) {
      for (size_t d = 0; d <= art[3].size(); d++) {
        if (check(b, d, art[0].size(), art[1].size(), art[2].size(),
                  art[3].size())) {
          found = true;
          size_t a = (n >> 1) - art[1].size() - art[3].size() + d;
          size_t c = art[1].size() + art[3].size() - b - (d << 1);
          for (size_t i = 0; i < a; i++) {
            ans.push_back(art[0][i]);
          }
          for (size_t i = 0; i < b; i++) {
            ans.push_back(art[1][i]);
          }
          for (size_t i = 0; i < c; i++) {
            ans.push_back(art[2][i]);
          }
          for (size_t i = 0; i < d; i++) {
            ans.push_back(art[3][i]);
          }
          break;
        }
      }
      if (found) {
        break;
      }
    }
    if (!found) {
      puts("-1");
      continue;
    }
    printf("%d", ans[0] + 1);
    for (size_t i = 1; i < ans.size(); i++) {
      printf(" %d", ans[i] + 1);
    }
    puts("");
  }
  return 0;
}
