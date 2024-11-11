#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int a[111];
bool vis[111];
int main() {
  cin >> n >> k;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", a + i);
  }
  int siz = n / k;
  cin >> m;
  double Max = -1, Min = 101;
  for (int i = (1); i <= (m); i++) {
    double sum = 0;
    for (int j = (1); j <= (siz); j++) {
      int x;
      scanf("%d", &x);
      sum += a[x];
      vis[x] = 1;
    }
    sum /= siz;
    Max = max(sum, Max);
    Min = min(sum, Min);
  }
  vector<int> b;
  b.clear();
  for (int i = (1); i <= (n); i++) {
    if (!vis[i]) b.push_back(a[i]);
  }
  sort((b).begin(), (b).end());
  int bsiz = b.size();
  if (bsiz >= siz) {
    double sum;
    sum = 0;
    for (int i = (0); i <= (siz - 1); i++) sum += b[i];
    Min = min(Min, sum / siz);
    sum = 0;
    for (int i = (bsiz - siz); i <= (bsiz - 1); i++) sum += b[i];
    Max = max(Max, sum / siz);
  }
  printf("%.10f %.10f\n", Min, Max);
  return 0;
}
