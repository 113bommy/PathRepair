#include <bits/stdc++.h>
using namespace std;
vector<int> num[26];
int po[26];
char str[300010];
long long ans[26];
struct node {
  int po;
  int v;
} ask[26];
bool cmp(node a, node b) { return a.po < b.po; }
int main() {
  scanf("%s", str);
  int len = strlen(str);
  memset(po, -1, sizeof(po));
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < len; i++) {
    num[str[i] - 'a'].push_back(i);
    po[str[i] - 'a'] = 0;
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < 26; j++) {
      if (po[j] != -1 && po[j] < num[j].size()) {
        ask[j].po = num[j][po[j]];
        ask[j].v = j;
      } else {
        ask[j].po = -1;
      }
    }
    sort(ask, ask + 26, cmp);
    int tot = 0, Po = i;
    for (int j = 0; j < 26; j++) {
      if (ask[j].po != -1) {
        ans[tot] += ask[j].po - Po;
        tot++;
        Po = ask[j].po;
      }
    }
    ans[tot] += len - Po;
    for (int j = 0; j < 26; j++) {
      if (ask[j].po != -1) {
        po[ask[j].v]++;
        break;
      }
    }
  }
  int i;
  for (i = 1; i <= 26; i++)
    if (ans[i] == -1) break;
  printf("%d\n", i - 1);
  for (int i = 1; i <= 26; i++) {
    if (ans[i] != -1) {
      cout << ans[i] + 1 << endl;
    } else
      break;
  }
  return 0;
}
