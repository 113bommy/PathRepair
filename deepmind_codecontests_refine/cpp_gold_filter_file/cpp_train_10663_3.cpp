#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int n;
int x[1000010];
vector<int> ans;
int main() {
  scanf("%d", &n);
  int a;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    x[a] = 1;
  }
  int s = 1000000;
  int m = 0;
  for (int i = 1; i <= s; i++) {
    if (x[i] && !x[s - i + 1]) ans.push_back(s - i + 1);
    if (x[i] && x[s - i + 1]) m++;
  }
  m /= 2;
  int i = 1;
  while (m--) {
    while (x[i] == 1 || x[s - i + 1] == 1) {
      i++;
    }
    ans.push_back(i);
    ans.push_back(s - i + 1);
    i++;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++)
    printf("%d%c", ans[i], (i == (int)ans.size() - 1) ? 10 : ' ');
  return 0;
}
