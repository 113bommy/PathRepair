#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 55;
const int INF = 1e9 + 77;
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
const double EPS = 1e-7;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> skill(n);
  vector<int> skills(n);
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    skill[i] = skills[i] = x;
  }
  sort(skills.begin(), skills.end());
  for (int i = 0; i < n; ++i) {
    int target = skill[i];
    int cur =
        lower_bound(skills.begin(), skills.end(), target) - skills.begin();
    ans[i] = cur;
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (skill[x] > skill[y])
      --ans[x];
    else if (skill[y] > skill[x])
      --ans[y];
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", &ans[i]);
  }
  return 0;
}
