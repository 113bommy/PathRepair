#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
bool visit[maxn] = {false};
vector<int> vc;
int main() {
  int i, j, k;
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &k);
    visit[k] = true;
  }
  n = maxn - 1;
  int cnt = 0;
  for (i = 1; i <= n / 2; ++i) {
    if (visit[i]) {
      if (visit[n - i + 1]) {
        ++cnt;
      } else {
        visit[n - i + 1] = true;
        vc.push_back(n - i + 1);
      }
    } else if (visit[n - i + 1]) {
      visit[i] = true;
      vc.push_back(i);
    }
  }
  for (i = 1; cnt && i <= n / 2; ++i) {
    if (!visit[i]) {
      --cnt;
      vc.push_back(i);
      vc.push_back(n - i + 1);
    }
  }
  printf("%d\n", vc.size());
  for (i = 0; i < vc.size(); ++i) printf("%d ", vc[i]);
  putchar('\n');
  return 0;
}
