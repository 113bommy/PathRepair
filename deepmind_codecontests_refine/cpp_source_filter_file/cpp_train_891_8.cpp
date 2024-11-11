#include <bits/stdc++.h>
using namespace std;
int k1, k2;
int n;
vector<int> s[2];
int status[2][7005];
bool vst[2][7005];
int cnt[2][7005];
void dfsStatus(int person, int idx) {
  vst[person][idx] = true;
  for (int cur : s[person]) {
    int flag = 0;
    int tar = (idx - cur + n) % n;
    if (vst[!person][tar]) continue;
    if (status[person][idx] == 2)
      status[!person][tar] = flag = 1;
    else {
      cnt[!person][tar];
      if (cnt[!person][tar] == 0) status[!person][tar] = flag = 2;
    }
    if (flag) dfsStatus(!person, tar);
  }
}
int main() {
  int tmp, tar;
  scanf("%d", &n);
  scanf("%d", &k1);
  for (int i = 1; i <= k1; i++) {
    scanf("%d", &tmp);
    s[0].push_back(tmp);
  }
  scanf("%d", &k2);
  for (int i = 1; i <= k2; i++) {
    scanf("%d", &tmp);
    s[1].push_back(tmp);
  }
  status[0][0] = status[1][0] = 2;
  vst[0][0] = vst[1][0] = true;
  for (int i = 0; i < n; i++) {
    cnt[0][i] = k2;
    cnt[1][i] = k1;
  }
  dfsStatus(0, 0);
  dfsStatus(1, 0);
  for (int i = 1; i < n; i++)
    if (status[1][i] == 2)
      printf("Lose ");
    else if (status[1][i] == 1)
      printf("Win ");
    else
      printf("Loop ");
  printf("\n");
  for (int i = 1; i < n; i++)
    if (status[0][i] == 2)
      printf("Lose ");
    else if (status[0][i] == 1)
      printf("Win ");
    else
      printf("Loop ");
  return 0;
}
