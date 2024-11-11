#include <bits/stdc++.h>
using namespace std;
int data[105];
int cnt[2000005];
vector<int> V;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    V.clear();
    int n;
    scanf("%d", &n);
    for (int i = (1); i < (n + 1); i++) scanf("%d", &data[i]);
    sort(data + 1, data + n + 1);
    int flag = 0;
    for (int i = (2); i < (n + 1); i++)
      if (data[i] == data[i - 1]) flag = 1;
    if (flag) {
      puts("NO");
      continue;
    }
    for (int i = (1); i < (1000001); i++) {
      int flag = 1;
      for (int j = (1); j < (n + 1); j++)
        if (cnt[data[j] + i]) flag = 0;
      if (flag) {
        V.push_back(i);
        for (int j = (1); j < (n + 1); j++) cnt[data[j] + i] = 1;
      }
      if ((int)(V).size() == n) break;
    }
    if ((int)(V).size() < n) {
      puts("NO");
      continue;
    } else {
      puts("YES");
      for (int i = (0); i < (n); i++)
        printf("%d%c", V[i], i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
