#include <bits/stdc++.h>
using namespace std;
int vis[101];
vector<vector<int> > TwoPr(2);
vector<int> nums;
int ans[201];
int viss[201];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    int k;
    cin >> k;
    vis[k]++;
    nums.push_back(k);
  }
  int turn = 0;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 10; i <= 99; i++) {
    if (vis[i] == 1) {
      TwoPr[turn].push_back(i);
      vis[i] = 0;
      turn = 1 - turn;
      if (!turn)
        cnt1++;
      else
        cnt2++;
    }
  }
  turn = 1;
  int dist1 = cnt1, dist2 = cnt2;
  for (int i = 10; i <= 99; i++) {
    if (vis[i]) {
      dist1++, dist2++;
      while (vis[i]) {
        while (turn == 1 && vis[i]) {
          vis[i]--;
          cnt2++;
          TwoPr[turn].push_back(i);
          turn = 1 - turn;
        }
        while (turn == 0 && vis[i]) {
          cnt1++;
          vis[i]--;
          TwoPr[turn].push_back(i);
          turn = 1 - turn;
        }
      }
    }
  }
  cout << dist1 * dist2 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      if (TwoPr[1][i] == nums[j] && !vis[j]) {
        ans[j] = 1;
        viss[j] = 1;
        break;
      }
    }
  }
  for (int i = 0; i < 2 * n; i++)
    printf("%d%c", ans[i] + 1, " \n"[i + 1 == 2 * n]);
  return 0;
}
