#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int cost[MAX];
vector<int> tims;
int main() {
  int n;
  scanf("%d", &n);
  int cc = 0;
  cost[0] = 0;
  tims.push_back(-1);
  int cpaid = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    int val = cost[i - 1] + 20;
    int ind =
        upper_bound(tims.begin(), tims.end(), max(0, a - 90)) - tims.begin();
    ind--;
    val = min(val, cost[ind] + 50);
    ind =
        upper_bound(tims.begin(), tims.end(), max(0, a - 1440)) - tims.begin();
    ind--;
    val = min(val, cost[ind] + 120);
    printf("%d\n", val - cpaid);
    cpaid = val;
    cost[i] = val;
    tims.push_back(a);
  }
}
