#include <bits/stdc++.h>
using namespace std;
const int P[] = {1, 10, 100, 1000};
int F(int a, int b) {
  int i, j;
  vector<int> v;
  for (i = (0); i < (4); ++i) {
    int d = a / P[i] % 10;
    for (j = (0); j < (d); ++j) v.push_back(a - d * P[i] + j * P[i]);
  }
  sort((v).begin(), (v).end());
  for (i = (0); i < (int((v).size())); ++i)
    if (v[i] >= b) return v[i];
  return 2012;
}
int main() {
  int N;
  scanf("%d", &N);
  int i;
  vector<int> res;
  int prev = 1000;
  for (i = (0); i < (N); ++i) {
    int a;
    scanf("%d", &a);
    prev = F(a, prev);
    res.push_back(prev);
  }
  if (prev > 2011)
    printf("No solution\n");
  else
    for (i = (0); i < (N); ++i) printf("%d\n", res[i]);
  return 0;
};
