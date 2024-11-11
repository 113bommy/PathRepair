#include <bits/stdc++.h>
using namespace std;
const int N = 100008;
int n, a[N];
vector<pair<int, int> > ans;
int main(void) {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  for (i = 1; i + 2 <= n; i++)
    if (a[i]) {
      for (k = 1, j = 2; i + j + j <= n; j++)
        if (a[i + j]) {
          k = j;
          break;
        }
      a[i] ^= 1;
      a[i + k] ^= 1;
      a[i + k + k] ^= 1;
      ans.push_back(make_pair(i, k));
    }
  if (a[n - 1] == 1 && a[n] == 0) {
    if (n >= 8) {
      ans.push_back(make_pair(n - 7, 1));
      ans.push_back(make_pair(n - 7, 3));
      ans.push_back(make_pair(n - 6, 1));
    } else {
      puts("NO");
      return 0;
    }
  } else if (a[n - 1] == 0 && a[n] == 1) {
    if (n >= 7) {
      ans.push_back(make_pair(n - 6, 1));
      ans.push_back(make_pair(n - 6, 3));
      ans.push_back(make_pair(n - 5, 1));
    } else {
      puts("NO");
      return 0;
    }
  } else if (a[n - 1] == 1 && a[n] == 1) {
    if (n >= 8) {
      ans.push_back(make_pair(n - 7, 1));
      ans.push_back(make_pair(n - 7, 3));
      ans.push_back(make_pair(n - 6, 1));
      ans.push_back(make_pair(n - 6, 1));
      ans.push_back(make_pair(n - 6, 3));
      ans.push_back(make_pair(n - 5, 1));
    } else {
      puts("NO");
      return 0;
    }
  }
  printf("YES\n%d\n", (int)ans.size());
  for (auto p : ans)
    printf("%d %d %d\n", p.first, p.first + p.second,
           p.first + p.second + p.second);
  return 0;
}
