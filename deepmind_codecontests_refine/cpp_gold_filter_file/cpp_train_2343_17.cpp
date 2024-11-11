#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000025;
int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  map<int, int> weight;
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    weight[w]++;
  }
  int result = 0;
  for (int i = 0; i < maxn; i++) {
    int cnt = weight.count(i);
    if (cnt != 0) {
      cnt = weight[i];
      result += (cnt % 2);
      if (cnt / 2 != 0) weight[i + 1] += cnt / 2;
    }
  }
  printf("%d\n", result);
  return 0;
}
