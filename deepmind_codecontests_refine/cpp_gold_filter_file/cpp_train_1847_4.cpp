#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 200200;
int a[N];
vector<tuple<int, int, int> > t;
int main() {
  int No_seq, n;
  scanf("%d", &No_seq);
  for (int i = 1; i <= No_seq; i++) {
    scanf("%d", &n);
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[j]);
      sum += a[j];
    }
    for (int j = 1; j <= n; j++) t.push_back(make_tuple(sum - a[j], i, j));
  }
  sort(t.begin(), t.end());
  for (int i = 1; i < t.size(); i++) {
    if (get<0>(t[i]) == get<0>(t[i - 1]) && get<1>(t[i]) != get<1>(t[i - 1])) {
      printf("YES\n");
      printf("%d %d\n", get<1>(t[i]), get<2>(t[i]));
      printf("%d %d\n", get<1>(t[i - 1]), get<2>(t[i - 1]));
      return 0;
    }
  }
  printf("NO");
  return 0;
}
