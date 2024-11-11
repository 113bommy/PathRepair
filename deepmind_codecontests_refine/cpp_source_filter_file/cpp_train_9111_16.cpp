#include <bits/stdc++.h>
using namespace std;
bool f[2000005] = {};
int a[1000005];
vector<int> ans;
int main() {
  for (int i = 2; i <= 2000005; i++) {
    if (f[i] == 0)
      for (int j = 2 * i; j <= 2000005; j += i) f[j] = 1;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] == 1 and a[1] == 1) {
    ans.push_back(1);
    ans.push_back(1);
    int i = 2;
    for (; i < n; i++)
      if (a[i] == 1)
        ans.push_back(1);
      else
        break;
    for (int i1 = i; i1 < n; i1++)
      if (f[a[i] + 1] == 0) {
        ans.push_back(a[i]);
        break;
      }
  } else {
    bool f1 = 1;
    for (int i = 0; i < n and f1 == 1; i++)
      for (int j = i + 1; j < n and f1 == 1; j++)
        if (f[a[i] + a[j]] == 0) {
          ans.push_back(a[i]);
          ans.push_back(a[j]);
          f1 = 0;
        }
    if (f1 == 1) ans.push_back(a[0]);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
