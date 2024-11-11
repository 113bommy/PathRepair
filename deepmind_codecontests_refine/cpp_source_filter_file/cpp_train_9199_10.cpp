#include <bits/stdc++.h>
using namespace std;
char str1[2000];
char str2[2000];
bool vis[1300007];
vector<string> map1[1300007];
long long ans1[1300007];
int main() {
  int k;
  while (~scanf("%s%s%d", str1, str2, &k)) {
    memset(vis, 0, sizeof(vis));
    int n = strlen(str1);
    int en = 0;
    for (int i = 0; i < n; i++) {
      int flag = 0;
      long long hash = 0;
      long long bas = 521;
      string str;
      for (int j = i; j < n; j++) {
        int t1 = str1[j] - 'a';
        if (str2[t1] == '0') flag++;
        if (flag > k) break;
        hash = hash * bas + str1[j];
        ans1[en++] = hash;
      }
    }
    sort(ans1, ans1 + en);
    int ans = unique(ans1, ans1 + en) - ans1;
    printf("%d\n", ans);
  }
  return 0;
}
