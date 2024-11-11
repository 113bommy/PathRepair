#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  vector<int> used(n, 0);
  vector<vector<int> > cycles;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cycles.push_back(vector<int>());
      int cur = i;
      while (!used[cur]) {
        used[cur] = true;
        cycles.back().push_back(cur);
        cur = p[cur] - 1;
      }
    }
  }
  sort(cycles.begin(), cycles.end(), [](vector<int> v1, vector<int> v2) {
    return (int)(v1).size() < (int)(v2).size();
  });
  if ((int)(cycles[0]).size() == 1) {
    puts("YES");
    int t = cycles[0][0];
    for (int i = 0; i < n; i++)
      if (i != t) printf("%d %d\n", t + 1, i + 1);
  } else if ((int)(cycles[0]).size() == 2) {
    bool ok = true;
    for (int i = 0; i < (int)(cycles).size(); i++)
      ok &= ((int)(cycles[i]).size() % 2 == 0);
    if (!ok) {
      puts("NO");
      return 0;
    }
    puts("YES");
    printf("%d %d\n", cycles[0][0] + 1, cycles[0][1] + 1);
    for (int i = 1; i < (int)(cycles).size(); i++) {
      for (int j = 0; j < (int)(cycles[i]).size(); j += 2) {
        printf("%d %d\n", cycles[0][0] + 1, cycles[i][j] + 1);
        printf("%d %d\n", cycles[0][1] + 1, cycles[i][j + 1] + 1);
      }
    }
  } else
    puts("NO");
  return 0;
}
