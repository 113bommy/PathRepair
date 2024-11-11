#include <bits/stdc++.h>
using namespace std;
vector<int> divv[300005];
int n, k;
int u[300005];
vector<pair<int, int> > vec;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i * j <= n; j++) {
      divv[i * j].push_back(i);
    }
  }
  for (int i = 2; i <= n; i++) {
    {
      int sz = divv[i].size();
      vec.push_back(make_pair(-sz, i));
    }
  }
  u[1] = 1;
  sort(vec.begin(), vec.end());
  int cur = 0;
  for (int i = 0; i < vec.size(); i++) {
    int num = vec[i].second, pre = cur;
    for (int j = 0; j < divv[num].size(); j++) cur += u[divv[num][j]];
    for (int j = 2; j * num <= n; j++) cur += u[j * num];
    if (cur > k) {
      cur = pre;
      continue;
    } else
      u[vec[i].second] = 1;
  }
  if (cur != k) {
    puts("No");
  } else {
    puts("Yes");
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += u[i];
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
      if (u[i]) printf("%d ", i);
    puts("");
  }
}
