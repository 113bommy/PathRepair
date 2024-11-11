#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
vector<int> costs;
vector<int> ans;
void init();
bool cmp(int a, int b);
int main() {
  int m, n, num1, num2;
  long long Ans = 0;
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &num1, &num2);
    costs.push_back(num2);
  }
  int index = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
  index = min(index, m);
  sort(costs.begin(), costs.end(), cmp);
  for (int i = 0; i < index; i++) {
    Ans += costs[i];
  }
  printf("%d\n", Ans);
  return 0;
}
void init() {
  for (int i = 1; i <= 100000; i++) {
    int temp;
    if (i % 2 == 0)
      temp = ((i - 1) * i + i) / 2;
    else
      temp = i * (i - 1) / 2;
    if (temp > maxn) break;
    ans.push_back(temp);
  }
}
bool cmp(int a, int b) { return a > b; }
