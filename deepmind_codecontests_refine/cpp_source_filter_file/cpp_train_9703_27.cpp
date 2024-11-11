#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5;
vector<int> v[N];
int main() {
  scanf("%d", &n);
  v[0].push_back(1);
  v[0].push_back(2);
  v[1].push_back(1);
  v[1].push_back(3);
  v[2].push_back(2);
  v[2].push_back(3);
  int k = 3, j = 3, i = 0;
  while (j <= n - k) {
    i = 0;
    while (i < j && k < n) {
      v[i].push_back(k);
      v[j].push_back(k);
      i++, k++;
    }
    j++;
  }
  printf("%d\n", j);
  for (int i = 0; i < int(j); i++) {
    for (auto x : v[i]) printf("%d ", x);
    puts(" ");
  }
  return 0;
}
