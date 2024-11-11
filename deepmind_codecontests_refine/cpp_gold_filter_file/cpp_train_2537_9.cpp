#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
const int INF = 1000000001;
pair<int, int> tab[MAX];
int n, m;
int sum;
void solve() {
  if (m <= 1) {
    printf("No\n");
    return;
  }
  printf("Yes\n");
  printf("%d ", tab[0].second + 1);
  for (int foo = 0; foo < tab[1].first - 1; ++foo)
    printf("%d %d ", tab[1].second + 1, tab[1].second + 1);
  printf("%d ", tab[0].second + 1);
  printf("%d ", tab[1].second + 1);
  for (int i = 2; i <= n - 1; ++i)
    for (int foo = 0; foo < tab[i].first; ++foo)
      printf("%d %d ", tab[i].second + 1, tab[i].second + 1);
  for (int foo = 0; foo < tab[0].first - m + 1; ++foo)
    printf("%d %d ", tab[0].second + 1, tab[0].second + 1);
  printf("%d ", tab[1].second + 1);
  for (int foo = 0; foo < m - 2; ++foo)
    printf("%d %d ", tab[0].second + 1, tab[0].second + 1);
  printf("\n");
}
int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tab[i].first);
    tab[i].second = i;
    sum += tab[i].first;
  }
  if (n == 1) {
    if (m != tab[0].first)
      printf("No\n");
    else {
      printf("Yes\n");
      for (int foo = 0; foo < tab[0].first; ++foo) printf("1 1 ");
      printf("\n");
    }
    return 0;
  }
  sort(tab, tab + n);
  vector<int> V;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < tab[i].first; ++j)
      V.push_back(tab[i].second + 1), V.push_back(tab[i].second + 1);
  if (m > sum) {
    printf("No\n");
    return 0;
  }
  if (m < tab[0].first) {
    solve();
    return 0;
  }
  printf("Yes\n");
  printf("%d ", V[0]);
  while (sum > m) {
    printf("%d %d ", V.back(), V.back());
    V.pop_back();
    V.pop_back();
    --sum;
  }
  for (int i = 1; i < V.size(); ++i) printf("%d ", V[i]);
  printf("\n");
  return 0;
}
