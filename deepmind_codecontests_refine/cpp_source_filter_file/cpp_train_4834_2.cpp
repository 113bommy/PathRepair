#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> pos;
vector<int> jmp;
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &n, &m, &k);
  pos.resize(k);
  jmp.resize(m);
  for (int i = 0, _i = m; i < _i; ++i) {
    scanf("%d", &jmp[i]);
  }
  for (int i = 0, _i = k; i < _i; ++i) {
    scanf("%d", &pos[i]);
  }
  int best = INT_MAX;
  vector<int> ans;
  for (int i = 0, _i = m; i < _i; ++i) {
    int cnt = 0;
    for (int j = 0, _j = k; j < _j; ++j) {
      if (jmp[i] < pos[j] && pos[j] % jmp[i] == 0) ++cnt;
    }
    if (cnt < best) {
      best = cnt;
      ans.clear();
      ans.push_back(i + 1);
    } else if (cnt == best) {
      ans.push_back(i + 1);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0, _i = ans.size(); i < _i; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
