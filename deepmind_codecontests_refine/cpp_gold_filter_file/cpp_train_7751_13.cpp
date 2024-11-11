#include <bits/stdc++.h>
using namespace std;
vector<int> dl, dl2;
int f1[100015];
int f2[100015];
int ans[100015];
int ile[100015];
int main() {
  ios_base::sync_with_stdio(0);
  int(n);
  scanf("%d", &(n));
  ;
  vector<int> v;
  for (int i = (0); i < (n); ++i) {
    int(a);
    scanf("%d", &(a));
    ;
    v.push_back(a);
  }
  dl.clear();
  dl2.clear();
  dl.push_back(0);
  for (int i = (0); i < (n); ++i) {
    vector<int>::iterator j = lower_bound(dl.begin(), dl.end(), v[i]);
    f1[i] = j - dl.begin();
    if (j == dl.end())
      dl.push_back(v[i]);
    else
      *j = v[i];
  }
  dl2.push_back(-1e6);
  for (int i = (0); i < (n); ++i) {
    vector<int>::iterator j =
        lower_bound(dl2.begin(), dl2.end(), -v[n - 1 - i]);
    f2[n - 1 - i] = j - dl2.begin();
    if (j == dl2.end())
      dl2.push_back(-v[n - 1 - i]);
    else
      *j = -v[n - 1 - i];
  }
  for (int i = (0); i < (n + 3); ++i) ile[i] = 0;
  int res = dl.size() - 1;
  for (int i = (0); i < (n); ++i) {
    if (f1[i] + f2[i] != res + 1)
      ans[i] = 1;
    else {
      ans[i] = 2;
      ile[f1[i]]++;
    }
  }
  for (int i = (0); i < (n); ++i) {
    if (ans[i] == 2 && ile[f1[i]] == 1) ans[i] = 3;
  }
  for (int i = (0); i < (n); ++i) printf("%d", ans[i]);
  printf("\n");
}
